*This project has been created as part of the 42 curriculum by ciparren.*

# get_next_line

## Description

`get_next_line` is a C function that reads a single line from a file descriptor each time it is called. A line is defined as a sequence of characters ending with a newline character `\n`, or by the end of the file if no newline is present. The function maintains an internal static buffer between calls, allowing it to handle partial reads and resume where it left off across successive invocations.

The implementation is built around three core operations:
- **Reading and buffering**: raw data is read from the file descriptor in chunks of `BUFFER_SIZE` bytes and accumulated in a persistent storage string.
- **Extracting the line**: once a newline is found (or EOF is reached), the next complete line is isolated and returned to the caller.
- **Cleaning the storage**: the consumed portion of the internal buffer is removed, preserving any remaining data for the next call.

The function handles standard files, standard input (`stdin`), and arbitrary file descriptors, returning `NULL` on error or end of file.

## Instructions

### Compilation

The project compiles as part of a larger program. Include `get_next_line.c`, `get_next_line_utils.c`, and `get_next_line.h` in your build.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

`BUFFER_SIZE` can be set at compile time using the `-D` flag. If not provided, it defaults to `42`.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1    ...   # smallest buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 ...   # large buffer
```

### Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

The caller is responsible for freeing each returned line. The function returns `NULL` when the end of the file is reached or if an error occurs.

### Norminette

```bash
norminette get_next_line.c get_next_line_utils.c get_next_line.h
```

All files comply with the 42 Norm.

## Functions

| File | Function | Description |
|---|---|---|
| `get_next_line.c` | `get_next_line` | Main entry point. Reads and returns one line per call. |
| `get_next_line.c` | `read_and_store` | Allocates the read buffer and drives the read loop. |
| `get_next_line.c` | `read_loop` | Reads from the fd until a newline is found or EOF is reached. |
| `get_next_line.c` | `extract_line` | Copies the first line (up to and including `\n`) from storage. |
| `get_next_line.c` | `clean_storage` | Removes the consumed line from the persistent buffer. |
| `get_next_line_utils.c` | `ft_strlen` | Returns the length of a string. NULL-safe. |
| `get_next_line_utils.c` | `search_n` | Returns 1 if a newline character is found in the string. |
| `get_next_line_utils.c` | `ft_strjoin` | Concatenates two strings into a new allocation. Frees the first argument. |
| `get_next_line_utils.c` | `ft_substr` | Returns a substring of length `len` starting at `start`. |

## Resources

### Documentation and references

- [`man 2 read`](https://man7.org/linux/man-pages/man2/read.2.html) — understanding return values (0 = EOF, -1 = error) and blocking behaviour on stdin.
- [`man 3 malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html) — memory allocation and failure handling.
- 42 project subject PDF — specification of expected behaviour for edge cases (empty lines, no trailing newline, invalid fd).
- [Valgrind documentation](https://valgrind.org/docs/manual/quick-start.html) — used to verify absence of memory leaks during testing.

### Use of artificial intelligence

AI assistance (Claude) was used in the following ways during this project:

- **Conceptual clarification**: understanding the difference between stack-allocated and statically-allocated variables, and why a `static` variable is necessary to persist the buffer between calls.
- **Debugging**: tracing double-free scenarios when `ft_strjoin` frees its first argument and the caller also attempts to free the same pointer.
- **Edge case analysis**: reasoning through behaviour when `BUFFER_SIZE = 1`, when the last line has no trailing newline, and when `read()` returns -1.

All final implementation decisions and the written code are the author's own work.