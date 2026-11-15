# Libft Testing & Quality Assurance Guide

This guide describes how to build, test, and verify the `Libft_42-cursus` library. It covers Makefile targets, linking procedures, edge-case testing, memory leak detection with Valgrind, and explicit boundaries regarding what has been verified versus unverified in this repository.

---

## Table of Contents

- [1. Building the Library](#1-building-the-library)
- [2. Makefile Targets](#2-makefile-targets)
- [3. Writing a Custom Test Runner](#3-writing-a-custom-test-runner)
- [4. Linking Against `libft.a`](#4-linking-against-libfta)
- [5. Systematic Edge-Case Matrix](#5-systematic-edge-case-matrix)
- [6. Memory Leak Detection (Valgrind & ASan)](#6-memory-leak-detection-valgrind-asan)
- [7. Automated Documentation Graph Validation](#7-automated-documentation-graph-validation)
- [8. Verification Boundaries](#8-verification-boundaries)

---

## 1. Building the Library

### Compilation Command

Due to an include path requirement (some source files `#include "libft.h"` while the header resides in `header/libft.h`), pass the include path flags during compilation:

```bash
make CFLAGS="-Wall -Wextra -Werror -Iheader -I."
```

This compiles each `.c` source file under `src/` to a corresponding `.o` object file and packages them into the static archive `libft.a` using the `ar` utility:

```bash
ar -r libft.a src/*.o
```

---

## 2. Makefile Targets

The repository's `Makefile` defines the standard 42 build targets:

| Target | Command | Purpose |
|---|---|---|
| `all` | `make all` | Compiles source files and archives `libft.a` (default target). |
| `clean` | `make clean` | Removes all compiled object files (`src/*.o`). |
| `fclean` | `make fclean` | Runs `clean` and removes the static library archive `libft.a`. |
| `re` | `make re` | Performs a full rebuild (`fclean` followed by `all`). |

### Verifying Archive Contents

To inspect the symbols and object files bundled inside `libft.a`:

```bash
ar -t libft.a
```

To list all exported symbols:

```bash
nm libft.a | grep " T "
```

---

## 3. Writing a Custom Test Runner

Create a standalone C test file (e.g., `main_test.c`) in your project or repository root:

```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void test_characters(void)
{
    assert(ft_isalpha('A') == 1);
    assert(ft_isalpha('z') == 1);
    assert(ft_isalpha('1') == 0);
    assert(ft_isdigit('5') == 1);
    assert(ft_isdigit('a') == 0);
    assert(ft_toupper('g') == 'G');
    assert(ft_tolower('Z') == 'z');
    printf("[PASS] Character classification & conversion\n");
}

static void test_memory(void)
{
    char buf[10];
    ft_memset(buf, 'X', 5);
    assert(buf[0] == 'X' && buf[4] == 'X');

    ft_bzero(buf, 5);
    assert(buf[0] == 0 && buf[4] == 0);

    char src[] = "123456789";
    ft_memcpy(buf, src, 5);
    assert(ft_memcmp(buf, "12345", 5) == 0);
    printf("[PASS] Memory manipulation\n");
}

static void test_strings(void)
{
    assert(ft_strlen("hello") == 5);
    assert(ft_strncmp("abc", "abd", 2) == 0);
    assert(ft_strncmp("abc", "abd", 3) != 0);

    char *dup = ft_strdup("42 Network");
    assert(dup != NULL);
    assert(strcmp(dup, "42 Network") == 0);
    free(dup);

    char *joined = ft_strjoin("Hello, ", "World!");
    assert(joined != NULL);
    assert(strcmp(joined, "Hello, World!") == 0);
    free(joined);
    printf("[PASS] String manipulation & creation\n");
}

static void test_numbers(void)
{
    assert(ft_atoi("   -42") == -42);
    assert(ft_atoi("+1337") == 1337);
    assert(ft_atoi("0") == 0);

    char *s1 = ft_itoa(0);
    assert(strcmp(s1, "0") == 0);
    free(s1);

    char *s2 = ft_itoa(-2147483648);
    assert(strcmp(s2, "-2147483648") == 0);
    free(s2);
    printf("[PASS] Integer & string conversion\n");
}

int main(void)
{
    printf("Starting Libft test suite...\n");
    test_characters();
    test_memory();
    test_strings();
    test_numbers();
    printf("All test assertions passed successfully!\n");
    return (0);
}
```

---

## 4. Linking Against `libft.a`

Compile and link the test runner with the following GCC/Clang command:

```bash
cc -Wall -Wextra -Werror -Iheader main_test.c -L. -lft -o test_runner
```

### Breakdown of Compiler Flags

- `-Iheader`: Directs the preprocessor to look for `libft.h` in the `header/` directory.
- `main_test.c`: The test driver source file.
- `-L.`: Instructs the linker to search the current directory for libraries.
- `-lft`: Links `libft.a` (the prefix `lib` and suffix `.a` are resolved automatically).
- `-o test_runner`: Specifies the output binary name.

Execute the compiled runner:

```bash
./test_runner
```

Clean up temporary binaries:

```bash
rm -f test_runner
```

---

## 5. Systematic Edge-Case Matrix

The following edge cases should be verified when testing Libft functions:

| Function | Critical Edge Case | Expected Safe Behavior |
|---|---|---|
| `ft_atoi` | `INT_MIN` (`-2147483648`) and `INT_MAX` (`2147483647`) | Evaluates without crash |
| `ft_atoi` | Arbitrary leading spaces and tabs (`\t`, `\n`, `\v`, `\f`, `\r`) | Skips all leading whitespace |
| `ft_atoi` | Multiple signs (e.g., `"--42"`, `"+-42"`) | Parses only first sign; returns `0` |
| `ft_itoa` | `0` | Allocates and returns `"0"` |
| `ft_itoa` | `INT_MIN` (`-2147483648`) | Returns `"-2147483648"` without overflow |
| `ft_memmove` | Destination overlaps source from above (`dst > src`) | Copies without overwriting unread bytes |
| `ft_memmove` | Destination overlaps source from below (`dst < src`) | Copies forward without corruption |
| `ft_memcpy` | `dst == src` | Returns `dst` immediately |
| `ft_memcpy` | `dst == NULL && src == NULL` | Returns `NULL` safely |
| `ft_strlcpy` | Destination size `0` | Writes 0 bytes, returns `strlen(src)` |
| `ft_strlcat` | `dst_size <= strlen(dst)` | Returns `dst_size + strlen(src)` |
| `ft_strchr` | Searching for `\0` (`c == 0`) | Returns pointer to null terminator |
| `ft_strnstr` | Needle is empty string `""` | Returns haystack pointer `(char *)big` |
| `ft_substr` | `start > strlen(s)` | Returns empty string `ft_strdup("")` |
| `ft_strjoin` | `s1 == NULL || s2 == NULL` | Returns `NULL` safely |
| `ft_strtrim` | Entire string composed of characters in `set` | Returns empty allocated string `""` |
| `ft_split` | Consecutive delimiters (e.g., `"hello,,,world"`) | Collapses delimiters, creates no empty words |
| `ft_split` | String starts or ends with delimiters | Trims delimiters before splitting |

---

## 6. Memory Leak Detection (Valgrind & ASan)

All heap allocations created by `malloc` must be freed before termination.

### Valgrind

Run the test executable under Valgrind to monitor heap blocks and detect memory leaks, uninitialized memory reads, or double-frees:

```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --error-exitcode=1 \
         ./test_runner
```

Expected output for leak-free execution:

```text
== ERROR SUMMARY: 0 errors from 0 contexts
== All heap blocks were freed -- no leaks are possible
```

### AddressSanitizer (ASan)

Compile with GCC or Clang's AddressSanitizer for runtime memory error detection:

```bash
cc -Wall -Wextra -Werror -fsanitize=address -g -Iheader main_test.c -L. -lft -o test_runner_asan
./test_runner_asan
rm -f test_runner_asan
```

---

## 7. Automated Documentation Graph Validation

To guarantee zero broken links, invalid anchors, or missing function entries across the documentation knowledge base, an automated verification script is provided in `tests/validate_docs.py`.

Run the test suite:

```bash
python3 tests/validate_docs.py
```

The script verifies:
- Every Markdown file link resolves to an existing file.
- Every section anchor matches an actual GitHub-compliant heading slug.
- All 34 functions declared in `header/libft.h` have dedicated entries in `docs/FUNCTIONS.md`.
- All 34 functions are indexed with direct links in `docs/README.md`.

---

## 8. Verification Boundaries

In accordance with strict verification rules:

- **Verified**:
  - The 34 C source files compile cleanly with `-Wall -Wextra -Werror` when the include path `-Iheader -I.` is provided.
  - The static library `libft.a` is successfully generated by `ar -r`.
  - Linking against external programs functions as documented.
  - Basic unit tests covering character classification, memory operations, strings, and integer conversion pass.
- **Unverified**:
  - **42 Norminette**: `norminette` is not installed on this system; compliance with the official 42 Norm cannot be automatically confirmed.
  - **Automated 42 Test Suites**: Third-party evaluation suites (`francinette`, `libft-unit-test`, `tripouille`) are external and have not been executed in this environment.
  - **Deepthought / Moulinette Evaluation**: Official grading results for bonus linked-list functions or automated stress evaluation are not verified.

---

**Navigation**
- [Documentation Home](README.md)
- [Project README](../README.md)
- [Function Reference](FUNCTIONS.md)
- [Implementation Guide](IMPLEMENTATION.md)
- [Testing Guide](TESTING.md)
