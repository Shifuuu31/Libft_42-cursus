# Project Documentation Standard (PDS)

A reusable engineering standard for software documentation across 42 cursus assignments, open-source utilities, backend APIs, and systems repositories.

---

## 1. Principles & Objectives

1. **Accuracy Over Assertion**: Never document hypothetical, unverified, or intended functionality as established fact. If a feature or test has not been executed, explicitly label it as unverified.
2. **Scannability**: Developers read documentation to solve specific problems. Structure content with standard headers, concise tables, and clear code snippets.
3. **Reproducibility**: Every command, script, and code sample must be complete, tested, and copy-pasteable in the stated environment.
4. **Minimalism**: Documentation should be proportionate to project complexity. Small single-purpose utilities require only a clean `README.md`; complex architectures warrant a modular `docs/` tree.

---

## 2. Recommended Repository Layout

### Simple / Small Projects
For libraries, single-binary tools, or introductory school projects:

```text
my-project/
├── Makefile / CMakeLists.txt / Cargo.toml
├── README.md
├── include/ or header/
├── src/
└── tests/
```

### Complex / Multi-Component Projects
For advanced systems, frameworks, or full-stack applications:

```text
my-project/
├── README.md
├── docs/
│   ├── ARCHITECTURE.md          # System design, data flow, memory model
│   ├── API.md / FUNCTIONS.md     # Detailed interface or endpoint reference
│   ├── TESTING.md               # Test setup, edge cases, benchmarks
│   └── CONTRIBUTING.md          # Code standards, PR guidelines
├── src/
└── tests/
```

---

## 3. Standard README Structure

Every production-ready repository should feature a `README.md` containing the following sections in order:

```markdown
# Project Name

A concise one-line summary of what this project does and the problem it solves.

## Overview
A 1–2 paragraph technical description of the system, its architecture, and its primary capabilities.

## Objectives & Learning Outcomes (Academic / Portfolio)
Key engineering principles and competencies demonstrated by the codebase.

## Features
Bulleted list of core modules, supported data types, algorithms, or protocol specifications.

## Technology Stack
- Language: C (C99 / C11) / Go / Rust / C++ / TypeScript
- Compiler / Runtime: cc / gcc / clang / go / cargo
- Build Tool: GNU Make / CMake
- Dependencies: None (zero-dependency libc recreation)

## Repository Structure
A clean ASCII directory tree showing significant folders and files.

## Prerequisites
Exact tools, compilers, package versions, and operating system requirements.

## Installation & Compilation
Step-by-step build commands with compiler flags and default output binaries.

## Usage
A complete, self-contained, compilable code snippet or CLI invocation.

## API / Function Reference
Summary table linking to `docs/API.md` or `docs/FUNCTIONS.md`.

## Testing & Quality Assurance
Exact commands to run unit tests, sanitizers, or memory leak checks.

## Known Limitations & Edge Cases
Factual disclosures of unsupported edge cases, known bugs, or platform limitations.

## License / Academic Integrity Notice
Permissive license or statement of academic guidelines.
```

---

## 4. Technical Writing Style Guide

- **Voice & Tone**: Objective, professional, technical, and precise. Avoid marketing hyperbole ("blazing fast", "game-changing", "ultimate").
- **Language**: Standard technical English. Use active verbs ("allocates", "returns", "parses") rather than vague expressions ("does stuff with").
- **Terminology**: Use precise domain terms:
  - *Allocate* vs *instantiate*
  - *File descriptor* vs *file handle*
  - *Null-terminated string* vs *text*
  - *Undefined behavior* vs *crash*
- **Code Highlighting**: Always specify the language identifier for fenced code blocks (`c`, `bash`, `rust`, `go`, `text`).
- **File Links**: Use relative Markdown links for internal project files:
  ```markdown
  See [Function Reference](FUNCTIONS.md) for full signatures.
  ```

---

## 5. Code Example Conventions

Code samples in documentation must adhere to strict production standards:

1. **Complete & Compilable**: Never use ellipsis (`...`) for critical control flow. Include necessary headers and `main()` definitions.
2. **Error Handling**: Demonstrate checking for allocation failures (`if (!ptr)`), system call errors (`-1`), or null pointers.
3. **Resource Cleanup**: Free all heap allocations and close open file descriptors before exit to avoid demonstrating bad practices.
4. **Real Compilation Instructions**: Provide the exact CLI command needed to build and run the example.

---

## 6. API & Function Documentation Template

When documenting functions, endpoints, or data structures, use this standard schema:

```markdown
### `function_name`

```language
signature_here
```

- **Purpose**: What the function does in 1–2 sentences.
- **Parameters**:
  - `param_1`: Description and constraints.
  - `param_2`: Description and constraints.
- **Return Value**: Exact return conditions on success and error.
- **Memory Ownership**: Specifies if caller must free or close the return value.
- **Edge Cases & Errors**: Specific behavior on null pointers, boundary limits, or failure states.
- **Standard Equivalent**: Comparison with POSIX, libc, or standard library specs (if applicable).
```

---

## 7. Testing & Verification Standards

To maintain credibility:

- **Strict Categorization**:
  - **Verified**: Explicitly tested with documented commands in the stated environment.
  - **Unverified**: Intended or historical features that were not validated in the current test environment.
- **Sanitizers & Leak Detection**:
  - C/C++: Include Valgrind (`--leak-check=full`) and AddressSanitizer (`-fsanitize=address`) commands.
  - Rust: Include `cargo test` and `cargo miri test`.
  - Go: Include `go test -race -v ./...`.
- **Edge-Case Matrix**: Document boundary tests (min/max values, empty inputs, null pointers, concurrency limits).

---

## 8. Diagrams and Visuals

- **Mermaid Diagrams**: Use GitHub-supported Mermaid syntax (`flowchart TD`, `sequenceDiagram`, `stateDiagram-v2`).
- **No Decorative ASCII Banners**: Avoid enormous FIGlet/ASCII banners; use clear typography.
- **Screenshots / Terminal Output**: Only include terminal output when illustrating real CLI interactions or debugging traces. Fenced code blocks with `text` or `console` syntax are preferred over image files.

---

## 9. Mandatory Navigation & Indexing Framework

Documentation must be engineered as an interconnected knowledge graph rather than disjointed Markdown files. Every repository must enforce:

1. **Root Landing Page**: The root `README.md` acts as the project entrypoint, featuring a concise navigation block and quick-jump access links to installation, usage, and reference manuals.
2. **Central Documentation Homepage (`docs/README.md`)**: When a repository contains multiple documentation files, a central homepage must provide:
   - Quick navigation ("I want to...") matching developer intents to documentation files.
   - Comprehensive categorized and alphabetical item indexes with direct anchor links.
   - Prescribed learning paths (e.g. newcomer onboarding, deep-dive implementation, testing & contribution).
3. **Cross-Document Navigation Footers**: Every document must end with a standard, predictable navigation footer linking back to documentation home, project root, and key companion guides.
4. **Zero Broken Links**: The documentation graph must be systematically validated; every internal link and heading anchor must resolve without 404s.

---

## 10. Multi-Stack Adaptation Guide

| Stack | Build System | Testing Command | Memory / Analysis Tool | Primary Doc Files |
|---|---|---|---|---|
| **42 C Cursus** | GNU Make (`cc`, `ar`) | `make`, `./test_runner` | Valgrind, ASan, `norminette` | `README.md`, `docs/README.md`, `docs/FUNCTIONS.md`, `docs/TESTING.md` |
| **C / C++** | CMake / Meson | `ctest`, `ninja test` | Valgrind, Clang-Tidy, ASan/UBSan | `README.md`, `docs/README.md`, `docs/ARCHITECTURE.md` |
| **Rust** | Cargo | `cargo test` | `cargo clippy`, `cargo miri` | `README.md`, Rustdoc (`cargo doc`) |
| **Go** | Go Modules | `go test -race ./...` | `golangci-lint`, `pprof` | `README.md`, `docs/README.md`, `docs/API.md` |
| **Java** | Maven / Gradle | `mvn test` / `./gradlew test` | SpotBugs, JaCoCo | `README.md`, Javadoc |
| **Full-Stack / Web** | npm / pnpm / yarn | `npm test` | ESLint, TypeScript (`tsc --noEmit`) | `README.md`, `docs/README.md`, `docs/ARCHITECTURE.md` |
| **Backend REST / gRPC** | Language-dependent | Unit & integration tests | OpenAPI / Swagger, Postman | `README.md`, `docs/README.md`, `docs/ENDPOINTS.md` |

---

**Navigation**
- [Documentation Home](README.md)
- [Project README](../README.md)
- [Function Reference](FUNCTIONS.md)
- [Implementation Guide](IMPLEMENTATION.md)
- [Testing Guide](TESTING.md)
