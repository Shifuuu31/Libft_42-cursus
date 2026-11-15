#!/usr/bin/env python3
"""
validate_docs.py — Documentation Consistency & Link Verification Suite
Verifies all internal Markdown links, heading anchors, function index entries,
and header consistency across the Libft documentation graph.
"""

import os
import re
import sys

DOC_FILES = [
    "README.md",
    "docs/README.md",
    "docs/FUNCTIONS.md",
    "docs/IMPLEMENTATION.md",
    "docs/TESTING.md",
    "docs/PROJECT_DOCUMENTATION_STANDARD.md",
]

HEADER_FILE = "header/libft.h"


def github_slug(heading_text: str) -> str:
    """Computes GitHub-compliant heading anchor slug."""
    clean = heading_text.strip()
    slug = re.sub(r"[^\w\s-]", "", clean.lower()).strip()
    slug = re.sub(r"[-\s]+", "-", slug)
    return slug


def extract_anchors(filepath: str) -> set:
    """Extracts all heading anchors from a Markdown document."""
    anchors = set()
    with open(filepath, "r", encoding="utf-8") as f:
        in_code_block = False
        for line in f:
            stripped = line.strip()
            if stripped.startswith("```"):
                in_code_block = not in_code_block
                continue
            if in_code_block:
                continue
            if stripped.startswith("#"):
                heading_content = re.sub(r"^#+\s*", "", stripped).strip()
                # Compute slug
                slug = github_slug(heading_content)
                if slug:
                    anchors.add(slug)
    return anchors


def extract_links(filepath: str) -> list:
    """Extracts all markdown links [text](target) outside fenced code blocks."""
    links = []
    with open(filepath, "r", encoding="utf-8") as f:
        in_code_block = False
        for line_num, line in enumerate(f, start=1):
            stripped = line.strip()
            if stripped.startswith("```"):
                in_code_block = not in_code_block
                continue
            if in_code_block:
                continue
            # Match [text](target)
            matches = re.findall(r"\[([^\]]+)\]\(([^)]+)\)", line)
            for text, target in matches:
                links.append((line_num, text.strip(), target.strip()))
    return links


def verify_functions(errors: list):
    """Verifies all functions in libft.h are documented in FUNCTIONS.md and indexed in docs/README.md."""
    if not os.path.exists(HEADER_FILE):
        errors.append(f"Header file {HEADER_FILE} not found.")
        return

    with open(HEADER_FILE, "r", encoding="utf-8") as f:
        h_text = f.read()

    # Extract all ft_* functions declared in header
    proto_names = set(re.findall(r"\b(ft_[a-z0-9_]+)\s*\(", h_text))

    with open("docs/FUNCTIONS.md", "r", encoding="utf-8") as f:
        f_doc = f.read()

    with open("docs/README.md", "r", encoding="utf-8") as f:
        idx_doc = f.read()

    for fn in sorted(proto_names):
        # Must have dedicated section in FUNCTIONS.md: ### ft_<name>
        if f"### {fn}" not in f_doc:
            errors.append(f"Function {fn} missing '### {fn}' entry in docs/FUNCTIONS.md")
        # Must be indexed in docs/README.md
        if f"[{fn}](" not in idx_doc:
            errors.append(f"Function {fn} not linked in docs/README.md index")


def main():
    print("=" * 60)
    print("Libft Documentation Graph Verification Suite")
    print("=" * 60)

    # 1. Pre-compute anchors for all documentation files
    doc_anchors = {}
    for doc in DOC_FILES:
        if not os.path.exists(doc):
            print(f"[FATAL] Missing required documentation file: {doc}")
            sys.exit(1)
        doc_anchors[doc] = extract_anchors(doc)

    errors = []
    total_links_checked = 0

    # 2. Verify all links
    for doc in DOC_FILES:
        links = extract_links(doc)
        doc_dir = os.path.dirname(doc)

        for line_num, text, target in links:
            # Skip external URLs or mailto
            if target.startswith("http://") or target.startswith("https://") or target.startswith("mailto:"):
                continue

            total_links_checked += 1

            if target.startswith("#"):
                # Anchor in current document
                anchor = target[1:]
                if anchor not in doc_anchors[doc]:
                    errors.append(
                        f"{doc}:{line_num} -> Broken anchor '{target}' for link text '{text}'"
                    )
            elif "#" in target:
                # Inter-file link with anchor: path/to/file.md#anchor
                rel_path, anchor = target.split("#", 1)
                resolved_file = os.path.normpath(os.path.join(doc_dir, rel_path))
                if not os.path.exists(resolved_file):
                    errors.append(
                        f"{doc}:{line_num} -> Target file '{resolved_file}' not found (link '{target}')"
                    )
                elif resolved_file in doc_anchors:
                    if anchor not in doc_anchors[resolved_file]:
                        errors.append(
                            f"{doc}:{line_num} -> Anchor '{anchor}' not found in '{resolved_file}'"
                        )
            else:
                # Pure file link
                resolved_file = os.path.normpath(os.path.join(doc_dir, target))
                if not os.path.exists(resolved_file):
                    errors.append(
                        f"{doc}:{line_num} -> Target path '{resolved_file}' not found (link '{target}')"
                    )

    # 3. Verify function coverage and indexing
    verify_functions(errors)

    # 4. Report results
    print(f"Files inspected:        {len(DOC_FILES)}")
    print(f"Total links verified:   {total_links_checked}")

    if errors:
        print(f"\n[FAILED] Encountered {len(errors)} validation errors:")
        for err in errors:
            print(f"  - {err}")
        sys.exit(1)
    else:
        print("\n[SUCCESS] All links, anchors, and function index entries are 100% VALID!")
        sys.exit(0)


if __name__ == "__main__":
    main()
