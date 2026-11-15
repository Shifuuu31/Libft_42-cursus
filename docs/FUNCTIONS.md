# Libft Function Reference Manual

Welcome to the technical reference manual for all 34 functions implemented in `Libft_42-cursus`. This document provides a searchable, standardized specification for each function, detailing exact prototypes, parameters, return behaviors, memory ownership rules, systems mechanics, and edge cases.

---

## Table of Contents

- [Quick Navigation by Category](#quick-navigation-by-category)
- [Complete Alphabetical Function Index](#complete-alphabetical-function-index)
- [1. Character Classification & Conversion](#1-character-classification-conversion)
  - [ft_isalpha](#ft_isalpha)
  - [ft_isdigit](#ft_isdigit)
  - [ft_isalnum](#ft_isalnum)
  - [ft_isascii](#ft_isascii)
  - [ft_isprint](#ft_isprint)
  - [ft_toupper](#ft_toupper)
  - [ft_tolower](#ft_tolower)
- [2. Raw Memory Manipulation](#2-raw-memory-manipulation)
  - [ft_memset](#ft_memset)
  - [ft_bzero](#ft_bzero)
  - [ft_memcpy](#ft_memcpy)
  - [ft_memmove](#ft_memmove)
  - [ft_memchr](#ft_memchr)
  - [ft_memcmp](#ft_memcmp)
- [3. Dynamic Memory Allocation](#3-dynamic-memory-allocation)
  - [ft_calloc](#ft_calloc)
- [4. String Length, Searching & Comparison](#4-string-length-searching-comparison)
  - [ft_strlen](#ft_strlen)
  - [ft_strncmp](#ft_strncmp)
  - [ft_strchr](#ft_strchr)
  - [ft_strrchr](#ft_strrchr)
  - [ft_strnstr](#ft_strnstr)
- [5. String Sizing & Bounded Copying](#5-string-sizing-bounded-copying)
  - [ft_strlcpy](#ft_strlcpy)
  - [ft_strlcat](#ft_strlcat)
- [6. String Creation, Slicing & Transformation](#6-string-creation-slicing-transformation)
  - [ft_strdup](#ft_strdup)
  - [ft_substr](#ft_substr)
  - [ft_strjoin](#ft_strjoin)
  - [ft_strtrim](#ft_strtrim)
  - [ft_split](#ft_split)
  - [ft_strmapi](#ft_strmapi)
  - [ft_striteri](#ft_striteri)
- [7. Integer & String Conversions](#7-integer-string-conversions)
  - [ft_atoi](#ft_atoi)
  - [ft_itoa](#ft_itoa)
- [8. File Descriptor Output](#8-file-descriptor-output)
  - [ft_putchar_fd](#ft_putchar_fd)
  - [ft_putstr_fd](#ft_putstr_fd)
  - [ft_putendl_fd](#ft_putendl_fd)
  - [ft_putnbr_fd](#ft_putnbr_fd)

---

## Quick Navigation by Category

| Category | Count | Direct Links |
|---|---|---|
| **Character Checks & Conversion** | 7 | [ft_isalpha](#ft_isalpha), [ft_isdigit](#ft_isdigit), [ft_isalnum](#ft_isalnum), [ft_isascii](#ft_isascii), [ft_isprint](#ft_isprint), [ft_toupper](#ft_toupper), [ft_tolower](#ft_tolower) |
| **Raw Memory Manipulation** | 6 | [ft_memset](#ft_memset), [ft_bzero](#ft_bzero), [ft_memcpy](#ft_memcpy), [ft_memmove](#ft_memmove), [ft_memchr](#ft_memchr), [ft_memcmp](#ft_memcmp) |
| **Dynamic Memory Allocation** | 1 | [ft_calloc](#ft_calloc) |
| **String Length, Searching & Comparison** | 5 | [ft_strlen](#ft_strlen), [ft_strncmp](#ft_strncmp), [ft_strchr](#ft_strchr), [ft_strrchr](#ft_strrchr), [ft_strnstr](#ft_strnstr) |
| **String Sizing & Bounded Copying** | 2 | [ft_strlcpy](#ft_strlcpy), [ft_strlcat](#ft_strlcat) |
| **String Creation, Slicing & Transformation** | 7 | [ft_strdup](#ft_strdup), [ft_substr](#ft_substr), [ft_strjoin](#ft_strjoin), [ft_strtrim](#ft_strtrim), [ft_split](#ft_split), [ft_strmapi](#ft_strmapi), [ft_striteri](#ft_striteri) |
| **Integer & String Conversions** | 2 | [ft_atoi](#ft_atoi), [ft_itoa](#ft_itoa) |
| **File Descriptor Output** | 4 | [ft_putchar_fd](#ft_putchar_fd), [ft_putstr_fd](#ft_putstr_fd), [ft_putendl_fd](#ft_putendl_fd), [ft_putnbr_fd](#ft_putnbr_fd) |

---

## Complete Alphabetical Function Index

- **A**: [ft_atoi](#ft_atoi)
- **B**: [ft_bzero](#ft_bzero)
- **C**: [ft_calloc](#ft_calloc)
- **I**: [ft_isalnum](#ft_isalnum), [ft_isalpha](#ft_isalpha), [ft_isascii](#ft_isascii), [ft_isdigit](#ft_isdigit), [ft_isprint](#ft_isprint), [ft_itoa](#ft_itoa)
- **M**: [ft_memchr](#ft_memchr), [ft_memcmp](#ft_memcmp), [ft_memcpy](#ft_memcpy), [ft_memmove](#ft_memmove), [ft_memset](#ft_memset)
- **P**: [ft_putchar_fd](#ft_putchar_fd), [ft_putendl_fd](#ft_putendl_fd), [ft_putnbr_fd](#ft_putnbr_fd), [ft_putstr_fd](#ft_putstr_fd)
- **S**: [ft_split](#ft_split), [ft_strchr](#ft_strchr), [ft_strdup](#ft_strdup), [ft_striteri](#ft_striteri), [ft_strjoin](#ft_strjoin), [ft_strlcat](#ft_strlcat), [ft_strlcpy](#ft_strlcpy), [ft_strlen](#ft_strlen), [ft_strmapi](#ft_strmapi), [ft_strncmp](#ft_strncmp), [ft_strnstr](#ft_strnstr), [ft_strrchr](#ft_strrchr), [ft_strtrim](#ft_strtrim), [ft_substr](#ft_substr)
- **T**: [ft_tolower](#ft_tolower), [ft_toupper](#ft_toupper)

---

## 1. Character Classification & Conversion

### ft_isalpha

**Purpose:** Tests whether the character `c` is an alphabetic ASCII letter.

**Prototype:**
```c
int ft_isalpha(int c);
```

**Parameters:**
- `c`: Character code to test (passed as `int`).

**Returns:**
- `1` if `c` is an ASCII letter (`A-Z` or `a-z`).
- `0` otherwise.

**Behavior and implementation:**
Evaluates `(c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')`. Returns explicitly `1` rather than arbitrary non-zero values. Does not allocate dynamic memory.

**Example:**
```c
if (ft_isalpha('A'))
    ft_putendl_fd("Alphabetic character", 1);
```

**Related functions:**
- [ft_isdigit](#ft_isdigit), [ft_isalnum](#ft_isalnum), [ft_isascii](#ft_isascii), [ft_isprint](#ft_isprint)

---

### ft_isdigit

**Purpose:** Tests whether the character `c` is an ASCII decimal digit.

**Prototype:**
```c
int ft_isdigit(int c);
```

**Parameters:**
- `c`: Character code to test.

**Returns:**
- `1` if `c` is a decimal digit (`'0'` through `'9'`).
- `0` otherwise.

**Behavior and implementation:**
Evaluates `c >= '0' && c <= '9'`. Does not allocate dynamic memory.

**Example:**
```c
if (ft_isdigit('7'))
    ft_putendl_fd("Decimal digit", 1);
```

**Related functions:**
- [ft_isalpha](#ft_isalpha), [ft_isalnum](#ft_isalnum), [ft_atoi](#ft_atoi)

---

### ft_isalnum

**Purpose:** Tests whether the character `c` is alphanumeric (either an alphabetic letter or decimal digit).

**Prototype:**
```c
int ft_isalnum(int c);
```

**Parameters:**
- `c`: Character code to test.

**Returns:**
- `1` if `c` is alphanumeric.
- `0` otherwise.

**Behavior and implementation:**
Directly calls `ft_isdigit(c) || ft_isalpha(c)`.

**Example:**
```c
if (ft_isalnum('x') && ft_isalnum('9'))
    ft_putendl_fd("Both are alphanumeric", 1);
```

**Related functions:**
- [ft_isalpha](#ft_isalpha), [ft_isdigit](#ft_isdigit), [ft_isprint](#ft_isprint)

---

### ft_isascii

**Purpose:** Tests whether character `c` belongs to the 7-bit US-ASCII character set (values 0 through 127).

**Prototype:**
```c
int ft_isascii(int c);
```

**Parameters:**
- `c`: Value to test.

**Returns:**
- `1` if `0 <= c <= 127`.
- `0` otherwise.

**Behavior and implementation:**
Evaluates `c >= 0 && c < 128`.

**Example:**
```c
assert(ft_isascii(127) == 1);
assert(ft_isascii(128) == 0);
```

**Related functions:**
- [ft_isprint](#ft_isprint), [ft_isalpha](#ft_isalpha)

---

### ft_isprint

**Purpose:** Tests whether character `c` is a printable ASCII character, including space.

**Prototype:**
```c
int ft_isprint(int c);
```

**Parameters:**
- `c`: Character code to test.

**Returns:**
- `1` if `32 <= c <= 126`.
- `0` otherwise (control codes, delete, and values >= 128).

**Behavior and implementation:**
Evaluates `c >= 32 && c <= 126`.

**Example:**
```c
assert(ft_isprint(' ') == 1);
assert(ft_isprint('
') == 0);
```

**Related functions:**
- [ft_isascii](#ft_isascii), [ft_isalnum](#ft_isalnum)

---

### ft_toupper

**Purpose:** Converts a lowercase ASCII letter to its uppercase equivalent.

**Prototype:**
```c
int ft_toupper(int c);
```

**Parameters:**
- `c`: Character code to convert.

**Returns:**
- Uppercase equivalent (`c - 32`) if `c` is between `'a'` and `'z'`.
- `c` unchanged if not a lowercase letter.

**Behavior and implementation:**
Evaluates `if (c >= 'a' && c <= 'z') return (c - 32); return (c);`.

**Example:**
```c
char ch = ft_toupper('a'); // returns 'A'
```

**Related functions:**
- [ft_tolower](#ft_tolower), [ft_isalpha](#ft_isalpha)

---

### ft_tolower

**Purpose:** Converts an uppercase ASCII letter to its lowercase equivalent.

**Prototype:**
```c
int ft_tolower(int c);
```

**Parameters:**
- `c`: Character code to convert.

**Returns:**
- Lowercase equivalent (`c + 32`) if `c` is between `'A'` and `'Z'`.
- `c` unchanged if not an uppercase letter.

**Behavior and implementation:**
Evaluates `if (c >= 'A' && c <= 'Z') return (c + 32); return (c);`.

**Example:**
```c
char ch = ft_tolower('G'); // returns 'g'
```

**Related functions:**
- [ft_toupper](#ft_toupper), [ft_isalpha](#ft_isalpha)

---

## 2. Raw Memory Manipulation

### ft_memset

**Purpose:** Fills `len` bytes of the memory area pointed to by `s` with the constant byte `c`.

**Prototype:**
```c
void *ft_memset(void *s, int c, size_t len);
```

**Parameters:**
- `s`: Pointer to the destination memory block.
- `c`: Byte value to write (passed as `int`, converted to `unsigned char`).
- `len`: Number of bytes to fill.

**Returns:**
- The original destination pointer `s`.

**Behavior and implementation:**
Iterates from index 0 to `len - 1`, writing `*(unsigned char *)(s + i) = (unsigned char)c`. Memory ownership remains with caller.

**Example:**
```c
char buffer[16];
ft_memset(buffer, 0, sizeof(buffer));
```

**Related functions:**
- [ft_bzero](#ft_bzero), [ft_memcpy](#ft_memcpy), [ft_memmove](#ft_memmove)

---

### ft_bzero

**Purpose:** Erases the data in the `n` bytes of memory starting at `s` by writing zero bytes (`\0`).

**Prototype:**
```c
void ft_bzero(void *s, size_t n);
```

**Parameters:**
- `s`: Pointer to memory block.
- `n`: Number of bytes to clear.

**Returns:**
- None.

**Behavior and implementation:**
Directly delegates to `ft_memset(s, 0, n)`.

**Example:**
```c
int values[10];
ft_bzero(values, sizeof(values));
```

**Related functions:**
- [ft_memset](#ft_memset), [ft_calloc](#ft_calloc)

---

### ft_memcpy

**Purpose:** Copies `n` bytes from memory area `src` to memory area `dst`.

**Prototype:**
```c
void *ft_memcpy(void *dst, const void *src, size_t n);
```

**Parameters:**
- `dst`: Pointer to destination memory buffer.
- `src`: Pointer to source memory buffer.
- `n`: Number of bytes to copy.

**Returns:**
- The destination pointer `dst`.
- `NULL` if both `dst` and `src` are `NULL`.

**Behavior and implementation:**
Performs a sequential forward byte copy. Memory regions must not overlap; if buffers overlap such that `dst > src`, use `ft_memmove` instead to avoid data corruption.

**Example:**
```c
char src[] = "Data";
char dst[5];
ft_memcpy(dst, src, 5);
```

**Related functions:**
- [ft_memmove](#ft_memmove), [ft_memset](#ft_memset), [ft_strdup](#ft_strdup)

---

### ft_memmove

**Purpose:** Safely copies `len` bytes from memory area `src` to memory area `dst`, accommodating overlapping memory regions.

**Prototype:**
```c
void *ft_memmove(void *dst, const void *src, size_t len);
```

**Parameters:**
- `dst`: Pointer to destination buffer.
- `src`: Pointer to source buffer.
- `len`: Number of bytes to copy.

**Returns:**
- The destination pointer `dst`.

**Behavior and implementation:**
If `dst > src`, copies bytes in reverse order (from `len - 1` down to 0) to preserve unread source bytes. If `dst <= src`, delegates to `ft_memcpy(dst, src, len)`.

**Example:**
```c
char str[] = "123456789";
ft_memmove(str + 2, str, 5); // safely shifts "12345" forward
```

**Related functions:**
- [ft_memcpy](#ft_memcpy), [ft_memset](#ft_memset)

---

### ft_memchr

**Purpose:** Scans the initial `n` bytes of memory area `s` for the first occurrence of byte `c`.

**Prototype:**
```c
void *ft_memchr(const void *s, int c, size_t n);
```

**Parameters:**
- `s`: Pointer to memory block to scan.
- `c`: Target byte value (passed as `int`).
- `n`: Maximum number of bytes to examine.

**Returns:**
- Pointer to matching byte within `s`.
- `NULL` if byte is not found within `n` bytes.

**Behavior and implementation:**
Compares each byte as `(unsigned char)`. Returns `(char *)s + i` on first match.

**Example:**
```c
char data[] = {10, 20, 30, 40};
void *found = ft_memchr(data, 30, 4);
```

**Related functions:**
- [ft_memcmp](#ft_memcmp), [ft_strchr](#ft_strchr)

---

### ft_memcmp

**Purpose:** Compares the first `n` bytes of memory areas `str1` and `str2`.

**Prototype:**
```c
int ft_memcmp(const void *str1, const void *str2, size_t n);
```

**Parameters:**
- `str1`: Pointer to first memory block.
- `str2`: Pointer to second memory block.
- `n`: Number of bytes to compare.

**Returns:**
- `0` if all `n` bytes match or if `n == 0`.
- Difference between the first differing pair of bytes interpreted as `unsigned char` (`str1[i] - str2[i]`).

**Behavior and implementation:**
Performs unsigned byte-by-byte comparison, guaranteeing consistent ordering across signed and unsigned char architectures.

**Example:**
```c
if (ft_memcmp("abc", "abd", 3) != 0)
    ft_putendl_fd("Buffers differ", 1);
```

**Related functions:**
- [ft_memchr](#ft_memchr), [ft_strncmp](#ft_strncmp)

---

## 3. Dynamic Memory Allocation

### ft_calloc

**Purpose:** Allocates zero-initialized heap memory for an array of `n_items` elements of `size` bytes each.

**Prototype:**
```c
void *ft_calloc(size_t n_items, size_t size);
```

**Parameters:**
- `n_items`: Number of items to allocate.
- `size`: Size of each item in bytes.

**Returns:**
- Pointer to allocated and zero-filled memory block.
- `NULL` if memory allocation fails.

**Behavior and implementation:**
Calls `malloc(n_items * size)`. If successful, clears the allocated block with `ft_bzero`. Does not check for multiplication overflow. Caller owns the memory and must release it with `free()`.

**Example:**
```c
int *array = (int *)ft_calloc(10, sizeof(int));
if (array)
{
    // array is zeroed
    free(array);
}
```

**Related functions:**
- [ft_bzero](#ft_bzero), [ft_strdup](#ft_strdup)

---

## 4. String Length, Searching & Comparison

### ft_strlen

**Purpose:** Computes the number of characters in a null-terminated string.

**Prototype:**
```c
size_t ft_strlen(const char *s);
```

**Parameters:**
- `s`: Pointer to null-terminated string.

**Returns:**
- Total number of characters preceding the terminating null byte (`\0`).

**Behavior and implementation:**
Iterates with an index counter until `s[i] == '\0'`. Passing `NULL` causes a segmentation fault.

**Example:**
```c
size_t len = ft_strlen("Hello"); // returns 5
```

**Related functions:**
- [ft_strlcpy](#ft_strlcpy), [ft_strlcat](#ft_strlcat), [ft_strjoin](#ft_strjoin)

---

### ft_strncmp

**Purpose:** Compares up to `n` characters of two null-terminated strings.

**Prototype:**
```c
int ft_strncmp(const char *str1, const char *str2, size_t n);
```

**Parameters:**
- `str1`: First string.
- `str2`: Second string.
- `n`: Maximum number of characters to compare.

**Returns:**
- `0` if strings are equal over `n` characters or until both terminate.
- Difference between the first differing characters as `unsigned char` (`str1[i] - str2[i]`).

**Behavior and implementation:**
Terminates comparison when a null character is reached in either string or when `n` characters have been compared.

**Example:**
```c
if (ft_strncmp("prefix_cmd", "prefix_", 7) == 0)
    ft_putendl_fd("Prefix matched", 1);
```

**Related functions:**
- [ft_memcmp](#ft_memcmp), [ft_strnstr](#ft_strnstr)

---

### ft_strchr

**Purpose:** Locates the first occurrence of character `c` in null-terminated string `str`.

**Prototype:**
```c
char *ft_strchr(const char *str, int c);
```

**Parameters:**
- `str`: String to search.
- `c`: Character to locate (converted to `char`).

**Returns:**
- Pointer to first matching character in `str`.
- Pointer to terminating null byte if `c == '\0'`.
- `NULL` if character is not found.

**Behavior and implementation:**
Scans sequentially from start to terminating null character inclusive. Returns internal pointer into `str`.

**Example:**
```c
char *p = ft_strchr("path/to/file", '/');
```

**Related functions:**
- [ft_strrchr](#ft_strrchr), [ft_memchr](#ft_memchr), [ft_strtrim](#ft_strtrim)

---

### ft_strrchr

**Purpose:** Locates the last occurrence of character `c` in null-terminated string `str`.

**Prototype:**
```c
char *ft_strrchr(const char *str, int c);
```

**Parameters:**
- `str`: String to search.
- `c`: Character to locate.

**Returns:**
- Pointer to last matching character in `str`.
- Pointer to terminating null byte if `c == '\0'`.
- `NULL` if character is not found.

**Behavior and implementation:**
Scans forward to find string length, then searches backwards down to index 0.

**Example:**
```c
char *ext = ft_strrchr("archive.tar.gz", '.'); // points to ".gz"
```

**Related functions:**
- [ft_strchr](#ft_strchr)

---

### ft_strnstr

**Purpose:** Locates the first occurrence of substring `little` in string `big`, searching at most `len` characters.

**Prototype:**
```c
char *ft_strnstr(const char *big, const char *little, size_t len);
```

**Parameters:**
- `big`: The string to search within.
- `little`: The substring to locate.
- `len`: Maximum characters of `big` to examine.

**Returns:**
- `(char *)big` if `little` is empty (`""`).
- Pointer to beginning of substring in `big` if found within `len` characters.
- `NULL` if substring is not found.

**Behavior and implementation:**
Matches `little` up to index `len`. Evaluates `big[i]` before checking `i < len`, which triggers a segmentation fault if `big == NULL` even with `len == 0` (unless `little` is empty).

**Example:**
```c
char *pos = ft_strnstr("42 Network Cursus", "Network", 15);
```

**Related functions:**
- [ft_strncmp](#ft_strncmp), [ft_strchr](#ft_strchr)

---

## 5. String Sizing & Bounded Copying

### ft_strlcpy

**Purpose:** Copies up to `size - 1` characters from string `src` to `dst`, null-terminating the result.

**Prototype:**
```c
size_t ft_strlcpy(char *dst, const char *src, size_t size);
```

**Parameters:**
- `dst`: Destination buffer.
- `src`: Source string.
- `size`: Full capacity of destination buffer.

**Returns:**
- Total length of `src`. If return value `>= size`, truncation occurred.

**Behavior and implementation:**
Guarantees null termination if `size > 0`. If `size == 0`, destination is unmodified but `ft_strlen(src)` is still returned.

**Example:**
```c
char buf[8];
size_t needed = ft_strlcpy(buf, "42 Cursus", sizeof(buf));
if (needed >= sizeof(buf))
    ft_putendl_fd("Truncation occurred", 1);
```

**Related functions:**
- [ft_strlcat](#ft_strlcat), [ft_memcpy](#ft_memcpy), [ft_strlen](#ft_strlen)

---

### ft_strlcat

**Purpose:** Appends string `src` to `dst`, ensuring total string length is at most `dst_size - 1`.

**Prototype:**
```c
size_t ft_strlcat(char *dst, const char *src, size_t dst_size);
```

**Parameters:**
- `dst`: Destination buffer containing a null-terminated string.
- `src`: Source string to append.
- `dst_size`: Total capacity of destination buffer.

**Returns:**
- Initial length of `dst` plus length of `src`.
- If `dst_size <= ft_strlen(dst)`, returns `dst_size + ft_strlen(src)`.

**Behavior and implementation:**
Requires `dst` to be null-terminated within `dst_size`. Guarantees null termination if `dst_len < dst_size - 1`.

**Example:**
```c
char path[64] = "/usr/bin";
ft_strlcat(path, "/cc", sizeof(path));
```

**Related functions:**
- [ft_strlcpy](#ft_strlcpy), [ft_strlen](#ft_strlen), [ft_strjoin](#ft_strjoin)

---

## 6. String Creation, Slicing & Transformation

### ft_strdup

**Purpose:** Creates a duplicate of string `s` in newly allocated heap memory.

**Prototype:**
```c
char *ft_strdup(const char *s);
```

**Parameters:**
- `s`: String to duplicate.

**Returns:**
- Pointer to newly allocated string duplicate.
- `NULL` if memory allocation fails.

**Behavior and implementation:**
Allocates `ft_strlen(s) + 1` bytes via `malloc`, copies data via `ft_memcpy`, and returns the pointer. Caller must release with `free()`.

**Example:**
```c
char *dup = ft_strdup("libft");
if (dup)
{
    // use string
    free(dup);
}
```

**Related functions:**
- [ft_calloc](#ft_calloc), [ft_substr](#ft_substr), [ft_memcpy](#ft_memcpy)

---

### ft_substr

**Purpose:** Allocates and returns a substring from string `s`, starting at index `start` with maximum length `len`.

**Prototype:**
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

**Parameters:**
- `s`: Base string.
- `start`: Zero-based start index of substring.
- `len`: Maximum length of substring.

**Returns:**
- Pointer to newly allocated substring.
- `NULL` if allocation fails.

**Behavior and implementation:**
If `start > ft_strlen(s)`, returns an empty allocated string `ft_strdup("")`. Clamps `len` if `len > ft_strlen(s) - start`. Caller must release with `free()`.

**Example:**
```c
char *sub = ft_substr("42 Network", 3, 7); // returns "Network"
if (sub)
    free(sub);
```

**Related functions:**
- [ft_strdup](#ft_strdup), [ft_strjoin](#ft_strjoin), [ft_strtrim](#ft_strtrim)

---

### ft_strjoin

**Purpose:** Allocates and returns a new string formed by concatenating prefix `s1` and suffix `s2`.

**Prototype:**
```c
char *ft_strjoin(char const *s1, char const *s2);
```

**Parameters:**
- `s1`: Prefix string.
- `s2`: Suffix string.

**Returns:**
- Pointer to newly allocated combined string.
- `NULL` if allocation fails or if `!s1 || !s2`.

**Behavior and implementation:**
Allocates `ft_strlen(s1) + ft_strlen(s2) + 1` bytes. Copies `s1` followed by `s2`, null-terminating the result. Caller must release with `free()`.

**Example:**
```c
char *full = ft_strjoin("Hello, ", "World!");
if (full)
    free(full);
```

**Related functions:**
- [ft_substr](#ft_substr), [ft_strtrim](#ft_strtrim), [ft_strlen](#ft_strlen)

---

### ft_strtrim

**Purpose:** Returns a newly allocated copy of `s1` with all characters specified in `set` stripped from both ends.

**Prototype:**
```c
char *ft_strtrim(char const *s1, char const *set);
```

**Parameters:**
- `s1`: String to trim.
- `set`: Reference set of characters to strip.

**Returns:**
- Pointer to newly allocated trimmed string.
- `NULL` if allocation fails or if `!s1 || !set`.

**Behavior and implementation:**
Advances past leading characters matching `set` with `ft_strchr`, decrements end index while trailing characters match `set`, and returns `ft_substr(s1, 0, i + 1)`. Caller must release with `free()`.

**Example:**
```c
char *trimmed = ft_strtrim("   hello   ", " "); // returns "hello"
if (trimmed)
    free(trimmed);
```

**Related functions:**
- [ft_substr](#ft_substr), [ft_strchr](#ft_strchr), [ft_strlen](#ft_strlen)

---

### ft_split

**Purpose:** Splits string `s` using delimiter character `c` into a newly allocated, null-terminated array of strings (`char **`).

**Prototype:**
```c
char **ft_split(const char *s, char c);
```

**Parameters:**
- `s`: Null-terminated string to split.
- `c`: Delimiter character.

**Returns:**
- Pointer to newly allocated array of strings ending with `NULL`.
- `NULL` if allocation fails or if `*s == '\0'`.

**Behavior and implementation:**
Counts words, allocates array of pointers, and extracts each word using `ft_substr`. If word allocation fails, helper `ft_free` unrolls allocations (leaves index 0 un-freed). Caller must free each string element, then the outer array.

**Example:**
```c
char **tokens = ft_split("alpha,beta,gamma", ',');
if (tokens)
{
    for (int i = 0; tokens[i]; i++)
    {
        ft_putendl_fd(tokens[i], 1);
        free(tokens[i]);
    }
    free(tokens);
}
```

**Related functions:**
- [ft_substr](#ft_substr), [ft_strjoin](#ft_strjoin)

---

### ft_strmapi

**Purpose:** Applies function `f` to each character of string `s` with its index, creating a newly allocated transformed string.

**Prototype:**
```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

**Parameters:**
- `s`: Input string.
- `f`: Callback function accepting `(unsigned int index, char c)` returning new `char`.

**Returns:**
- Pointer to newly allocated string created from successive outputs of `f`.
- `NULL` if allocation fails or if `!s || !f`.

**Behavior and implementation:**
Allocates `ft_strlen(s) + 1` bytes and stores `f(i, s[i])` at each position. Input string is not modified. Caller must release with `free()`.

**Example:**
```c
static char rot1(unsigned int i, char c) { (void)i; return c + 1; }
char *shifted = ft_strmapi("abc", rot1); // returns "bcd"
if (shifted)
    free(shifted);
```

**Related functions:**
- [ft_striteri](#ft_striteri), [ft_strlen](#ft_strlen)

---

### ft_striteri

**Purpose:** Applies function `f` to each character of string `s` in place, passing its index and memory address.

**Prototype:**
```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

**Parameters:**
- `s`: Modifiable string buffer.
- `f`: Callback function accepting `(unsigned int index, char *c_ptr)`.

**Returns:**
- None.

**Behavior and implementation:**
Iterates through `s`, calling `f(i, &s[i])`. Safe against `!s || !f`. Mutates caller's buffer in place without heap allocations.

**Example:**
```c
static void upper_cb(unsigned int i, char *c) { (void)i; *c = ft_toupper(*c); }
char msg[] = "hello";
ft_striteri(msg, upper_cb); // msg becomes "HELLO"
```

**Related functions:**
- [ft_strmapi](#ft_strmapi), [ft_toupper](#ft_toupper)

---

## 7. Integer & String Conversions

### ft_atoi

**Purpose:** Converts the initial numeric substring of `str` into a signed integer.

**Prototype:**
```c
int ft_atoi(const char *str);
```

**Parameters:**
- `str`: String containing ASCII digits with optional leading whitespace and sign.

**Returns:**
- Converted signed integer value.

**Behavior and implementation:**
Skips leading whitespace (ASCII 32 and 9-13). Accepts optional single `+` or `-` sign. Accumulates digits in a signed 32-bit `int`. Does not guard against integer overflow.

**Example:**
```c
int val = ft_atoi("   -42abc"); // returns -42
```

**Related functions:**
- [ft_itoa](#ft_itoa), [ft_isdigit](#ft_isdigit)

---

### ft_itoa

**Purpose:** Converts signed integer `n` into a newly allocated null-terminated ASCII string.

**Prototype:**
```c
char *ft_itoa(int n);
```

**Parameters:**
- `n`: Signed integer to format.

**Returns:**
- Pointer to newly allocated string representation.
- `NULL` if allocation fails.

**Behavior and implementation:**
Computes required buffer size, handles negative numbers, and extracts digits with `ft_abs(n % 10) + '0'`. Correctly handles `INT_MIN` (`-2147483648`) without arithmetic overflow. Caller must release with `free()`.

**Example:**
```c
char *num = ft_itoa(-1337);
if (num)
{
    ft_putendl_fd(num, 1);
    free(num);
}
```

**Related functions:**
- [ft_atoi](#ft_atoi), [ft_putnbr_fd](#ft_putnbr_fd)

---

## 8. File Descriptor Output

### ft_putchar_fd

**Purpose:** Outputs character `c` directly to the open file descriptor `fd`.

**Prototype:**
```c
void ft_putchar_fd(char c, int fd);
```

**Parameters:**
- `c`: Character to write.
- `fd`: Target file descriptor (e.g. `1` for stdout, `2` for stderr).

**Returns:**
- None.

**Behavior and implementation:**
Performs unbuffered system call `write(fd, &c, 1)`.

**Example:**
```c
ft_putchar_fd('A', 1);
```

**Related functions:**
- [ft_putstr_fd](#ft_putstr_fd), [ft_putendl_fd](#ft_putendl_fd), [ft_putnbr_fd](#ft_putnbr_fd)

---

### ft_putstr_fd

**Purpose:** Outputs null-terminated string `s` directly to file descriptor `fd`.

**Prototype:**
```c
void ft_putstr_fd(char *s, int fd);
```

**Parameters:**
- `s`: String to write.
- `fd`: Target file descriptor.

**Returns:**
- None.

**Behavior and implementation:**
Contains null check `if (!s) return ;`. Writes `ft_strlen(s)` bytes via single `write(fd, s, len)` call.

**Example:**
```c
ft_putstr_fd("Status: OK
", 1);
```

**Related functions:**
- [ft_putchar_fd](#ft_putchar_fd), [ft_putendl_fd](#ft_putendl_fd), [ft_putnbr_fd](#ft_putnbr_fd)

---

### ft_putendl_fd

**Purpose:** Outputs null-terminated string `s` to file descriptor `fd`, followed by a newline (`
`).

**Prototype:**
```c
void ft_putendl_fd(char *s, int fd);
```

**Parameters:**
- `s`: String to write.
- `fd`: Target file descriptor.

**Returns:**
- None.

**Behavior and implementation:**
Writes `ft_strlen(s)` bytes followed by `
`. Passing `NULL` causes a segmentation fault in `ft_strlen`.

**Example:**
```c
ft_putendl_fd("Error: file not found", 2);
```

**Related functions:**
- [ft_putstr_fd](#ft_putstr_fd), [ft_putchar_fd](#ft_putchar_fd)

---

### ft_putnbr_fd

**Purpose:** Outputs signed integer `n` as ASCII digits directly to file descriptor `fd`.

**Prototype:**
```c
void ft_putnbr_fd(int n, int fd);
```

**Parameters:**
- `n`: Signed integer to output.
- `fd`: Target file descriptor.

**Returns:**
- None.

**Behavior and implementation:**
Uses recursive division by 10 to write digits in order. Explicitly intercepts `n == -2147483648` (`INT_MIN`) by writing `"-2147483648"` to prevent negative overflow.

**Example:**
```c
ft_putnbr_fd(42, 1);
ft_putchar_fd('
', 1);
```

**Related functions:**
- [ft_putchar_fd](#ft_putchar_fd), [ft_putstr_fd](#ft_putstr_fd), [ft_itoa](#ft_itoa)

---

**Navigation**
- [Documentation Home](README.md)
- [Project README](../README.md)
- [Function Reference](FUNCTIONS.md)
- [Implementation Guide](IMPLEMENTATION.md)
- [Testing Guide](TESTING.md)
- [Documentation Standard](PROJECT_DOCUMENTATION_STANDARD.md)
