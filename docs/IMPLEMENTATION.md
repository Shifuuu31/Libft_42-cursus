# Libft Implementation & Architecture Concepts

This document explores the fundamental systems programming and C concepts implemented throughout the `Libft_42-cursus` library. It bridges the gap between high-level language abstractions and low-level machine mechanics, illustrating how pointers, memory regions, dynamic allocation, integer representations, and system calls operate under the hood.

---

## Table of Contents

- [1. Pointers, Memory Layout, and Byte Addressing](#1-pointers-memory-layout-and-byte-addressing)
- [2. Memory Overlap & Safe Copying: `ft_memcpy` vs `ft_memmove`](#2-memory-overlap-safe-copying-ft_memcpy-vs-ft_memmove)
- [3. Dynamic Memory Allocation and Ownership](#3-dynamic-memory-allocation-and-ownership)
- [4. Multi-Allocation Error Recovery: The 2D Array Pattern](#4-multi-allocation-error-recovery-the-2d-array-pattern)
- [5. String Boundaries: Bounded Operations vs Legacy Strings](#5-string-boundaries-bounded-operations-vs-legacy-strings)
- [6. Two's Complement Integer Representation & `INT_MIN`](#6-twos-complement-integer-representation-int_min)
- [7. Function Pointers and Callback Architecture](#7-function-pointers-and-callback-architecture)
- [8. Unix File Descriptors and Unbuffered System Calls](#8-unix-file-descriptors-and-unbuffered-system-calls)

---

## 1. Pointers, Memory Layout, and Byte Addressing

In C, memory is a linear array of byte-addressable cells. A pointer is simply an integer storing a memory address, typed by the compiler to dictate how many bytes to read or write when dereferenced.

### `void *` vs Typed Pointers

Generic memory operations (`ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`) accept `void *` parameters. Because `void` has no concrete size, standard C forbids direct dereferencing or arithmetic on `void *`. To manipulate individual bytes, the pointer must be cast to a single-byte type:

```c
// Inside ft_memset.c:
*(unsigned char *)(s + i) = (unsigned char)c;
```

### Why `unsigned char *` for Byte Comparisons

Standard C specifies that memory functions (`memcmp`, `memchr`) treat bytes as `unsigned char`.

On platforms where `char` is signed (including x86_64 Linux), an 8-bit byte with the most significant bit set (e.g., `0xFF`, decimal 255) evaluates as `-1`. If compared using signed `char *`:

$$\text{signed: } 'a' (97) > 0xFF (-1)$$

With `unsigned char *`:

$$\text{unsigned: } 'a' (97) < 0xFF (255)$$

Using `(unsigned char *)` guarantees consistent, positive lexicographical ordering regardless of compiler signedness defaults.

---

## 2. Memory Overlap & Safe Copying: `ft_memcpy` vs `ft_memmove`

When copying contiguous blocks of memory between buffers, a naive byte-by-byte forward loop fails when the destination buffer overlaps the source buffer from above (`dst > src`).

```text
Non-overlapping or dst < src:
[ Source Bytes:  S0 | S1 | S2 | S3 ]
[ Dest Bytes:         D0 | D1 | D2 | D3 ]  --> Forward copy works safely

Overlapping where dst > src:
Buffer:   [ B0 | B1 | B2 | B3 | B4 ]
Source:   [ B0 | B1 | B2 ]  (len = 3)
Dest:          [ B1 | B2 | B3 ]

Forward copy step 1: Dest[0] (B1) = Source[0] (B0)  --> B1 is overwritten!
Forward copy step 2: Dest[1] (B2) = Source[1] (B1)  --> Copies overwritten B0, NOT original B1!
```

### The Reverse Copy Solution

`ft_memmove` detects whether `dst > src`. When destination starts at a higher address than source within the same buffer, it copies from highest index down to lowest (`len - 1` to `0`):

```c
// Inside ft_memmove.c:
if (dst > src)
{
    while (len > 0)
    {
        *(char *)(dst + len - 1) = *(char *)(src + len - 1);
        len--;
    }
}
else
{
    ft_memcpy(dst, src, len);
}
```

By copying the tail bytes first, data in earlier bytes is preserved until after it has been safely read.

---

## 3. Dynamic Memory Allocation and Ownership

C programs manage three primary memory regions:

1. **Stack**: Automatically managed, fixed-size frames tied to function invocation lifecycle.
2. **Data / BSS**: Static and global storage (strictly forbidden in 42 Libft).
3. **Heap**: Dynamically allocated at runtime via `malloc(3)` and explicitly released via `free(3)`.

### The Ownership Contract

Whenever a library function allocates memory on the heap, clear ownership rules determine who is responsible for calling `free`:

| Function | Allocation Target | Responsible Party for `free()` |
|---|---|---|
| `ft_calloc` | Raw zeroed byte buffer | Caller |
| `ft_strdup` | Null-terminated string copy | Caller |
| `ft_substr` | Sliced substring | Caller |
| `ft_strjoin` | Concatenated string | Caller |
| `ft_strtrim` | Trimmed string | Caller |
| `ft_itoa` | Formatted number string | Caller |
| `ft_strmapi` | Transformed string | Caller |
| `ft_split` | 2D string array (`char **`) | Caller (must free each string, then outer array) |

Functions that return newly allocated memory return `NULL` if `malloc` fails due to memory exhaustion. Robust callers must always check for `NULL` before dereferencing:

```c
char *s = ft_strdup("Example");
if (!s)
{
    // Handle allocation error
    return (1);
}
// Use string...
free(s);
```

---

## 4. Multi-Allocation Error Recovery: The 2D Array Pattern

`ft_split` represents one of the most complex memory patterns in Libft: a dynamically allocated array of pointers (`char **`), where each element points to an independently allocated string (`char *`).

```text
split (char **)  ---> [ ptr0 | ptr1 | ptr2 | NULL ]
                         |      |      |
                         v      v      v
                      "word1" "word2" "word3"
```

### Partial Allocation Failure Handling

If `malloc` succeeds for `split[0]` and `split[1]`, but fails on `split[2]`, simply returning `NULL` would leak `split[0]`, `split[1]`, and the outer `split` array itself.

To prevent memory leaks, `ft_split` implements an unwinding cleanup function:

```c
// Inside ft_split.c:
static void *ft_free(int j, char **p)
{
    while (j > 0)
    {
        free(p[j]);
        j--;
    }
    free(p);
    return (NULL);
}
```

*Implementation Observation*: In `src/ft_split.c`, the loop condition `while (j > 0)` decrements down to 1. As noted in the audit, index `p[0]` remains unfreed during an error rollback. In production code, the condition should be `while (j >= 0)` to guarantee zero leaks on allocation failure.

---

## 5. String Boundaries: Bounded Operations vs Legacy Strings

Standard C string functions like `strcpy` and `strcat` are notoriously dangerous because they lack bounds checking: they write bytes until encountering a null terminator in the source, risking buffer overflows and security vulnerabilities.

### Bounded Functions: `ft_strlcpy` and `ft_strlcat`

The BSD `strlcpy` and `strlcat` designs enforce two safety guarantees:

1. **Guaranteed Null Termination**: As long as destination buffer size is greater than 0, the output is guaranteed to have a terminating `'\0'`.
2. **Truncation Detection**: The functions return the total length of the string they *attempted* to create (`strlen(src)` for `strlcpy`, `strlen(dst) + strlen(src)` for `strlcat`). If the return value is greater than or equal to the buffer capacity, truncation occurred:

```c
char dst[10];
size_t needed = ft_strlcpy(dst, "Supercalifragilistic", sizeof(dst));
if (needed >= sizeof(dst))
{
    // String was truncated, but dst is safely null-terminated
}
```

---

## 6. Two's Complement Integer Representation & `INT_MIN`

On standard 32-bit two's complement architectures, signed integers range from:

$$\text{Range: } [-2^{31}, 2^{31} - 1] = [-2147483648, 2147483647]$$

Because negative numbers have one extra representable value than positive numbers, negating `INT_MIN` (`-(-2147483648)`) exceeds `INT_MAX` and causes undefined signed integer overflow.

### How `ft_putnbr_fd` and `ft_itoa` Handle `INT_MIN`

1. **Explicit Guard (`ft_putnbr_fd`)**:
   `ft_putnbr_fd` intercepts `n == -2147483648` immediately, outputting the string literal `"-2147483648"` directly without arithmetic negation.

2. **Modular Digit Extraction (`ft_itoa`)**:
   `ft_itoa` uses `n % 10` before negation. For `-2147483648`, `-2147483648 % 10` evaluates to `-8`. The helper `ft_abs(-8)` safely yields `8`. The number is then divided by 10 (`-214748364`), which falls well within normal positive negation bounds.

---

## 7. Function Pointers and Callback Architecture

C supports higher-order programming through function pointers. A function pointer stores the address of executable machine instructions in the code segment.

Libft demonstrates two callback patterns:

### Immutable Transformation: `ft_strmapi`

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

`ft_strmapi` treats the input string as immutable. It allocates a brand-new string and populates each index with the return value of callback `f(index, character)`.

### In-Place Mutation: `ft_striteri`

```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

`ft_striteri` takes a pointer to each character `&s[i]`. The callback function can mutate the character in-place without heap allocations:

```c
static void make_uppercase(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

// In application code:
char str[] = "hello";
ft_striteri(str, make_uppercase); // str becomes "HELLO"
```

---

## 8. Unix File Descriptors and Unbuffered System Calls

The `ft_put*_fd` functions interact directly with the operating system kernel via the `write(2)` system call:

```c
ssize_t write(int fd, const void *buf, size_t count);
```

### Standard Streams and File Descriptors

A file descriptor is a non-negative integer representing an open file or stream entry in the operating system's per-process file table:

- `0`: Standard Input (`stdin`)
- `1`: Standard Output (`stdout`)
- `2`: Standard Error (`stderr`)
- `>= 3`: Explicitly opened files, pipes, or network sockets

Unlike standard library I/O functions (`printf`, `puts`, `fwrite`) which buffer output in user space before flushing to the OS kernel, `ft_putchar_fd` and `ft_putstr_fd` trigger immediate system calls via `write(2)`. This ensures output is written directly without delay, even if the program terminates unexpectedly.

---

**Navigation**
- [Documentation Home](README.md)
- [Project README](../README.md)
- [Function Reference](FUNCTIONS.md)
- [Implementation Guide](IMPLEMENTATION.md)
- [Testing Guide](TESTING.md)
