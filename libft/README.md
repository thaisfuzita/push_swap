*This project has been created as part of the 42 curriculum by tjulya-c*

## Description

**libft** is a custom C library that reimplements a collection of standard C library functions, along with additional utility functions for string manipulation, memory management, and linked list operations.

The goal of this project is to deepen understanding of fundamental C programming concepts, including:
- Memory allocation and management
- Pointer manipulation
- String handling
- Data structures (specifically linked lists)

## Instructions

### Compilation

To compile the library:

```bash
make
```

This will generate `libft.a` in the root directory.

### Cleanup

- Remove object files: `make clean`
- Remove object files and library: `make fclean`
- Recompile everything: `make re`

### Usage in your projects

Include the header in your C files:

```c
#include "libft.h"
```

Compile with the library:

```bash
cc main.c -L. -lft -o my_program
```

## Library Functions

### Part 1 - Libc Functions

| Function | Description |
|--------|-----------|
| ft_atoi | Convert string to integer |
| ft_bzero | Zero out a memory area |
| ft_calloc | Allocate and zero-initialize memory |
| ft_isalnum | Check for alphanumeric character |
| ft_isalpha | Check for alphabetic character |
| ft_isascii | Check for ASCII character |
| ft_isdigit | Check for digit (0-9) |
| ft_isprint | Check for printable character |
| ft_memchr | Locate byte in memory |
| ft_memcmp | Compare memory areas |
| ft_memcpy | Copy memory area |
| ft_memmove | Copy memory area with overlap handling |
| ft_memset | Fill memory with constant byte |
| ft_strchr | Locate character in string |
| ft_strdup | Duplicate string |
| ft_strlcat | Size-bounded string concatenation |
| ft_strlcpy | Size-bounded string copy |
| ft_strlen | Calculate string length |
| ft_strncmp | Compare strings (size-bounded) |
| ft_strnstr | Locate substring (size-bounded) |
| ft_strrchr | Locate character in string (reverse) |
| ft_tolower | Convert character to lowercase |
| ft_toupper | Convert character to uppercase |

### Part 2 - Additional Functions

| Function | Description |
|--------|-----------|
| ft_itoa | Convert integer to string |
| ft_putchar_fd | Output character to file descriptor |
| ft_putendl_fd | Output string with newline to file descriptor |
| ft_putnbr_fd | Output integer to file descriptor |
| ft_putstr_fd | Output string to file descriptor |
| ft_split | Split string into array of substrings |
| ft_striteri | Apply function to each character (with index) |
| ft_strjoin | Concatenate two strings |
| ft_strmapi | Create new string by applying function |
| ft_strtrim | Trim characters from beginning and end |
| ft_substr | Extract substring |

### Part 3 - Linked List Functions

| Function | Description |
|--------|-----------|
| ft_lstnew | Create new list node |
| ft_lstadd_front | Add node at beginning |
| ft_lstadd_back | Add node at end |
| ft_lstsize | Count list nodes |
| ft_lstlast | Get last node |
| ft_lstdelone | Delete single node |
| ft_lstclear | Delete entire list |
| ft_lstiter | Apply function to all nodes |
| ft_lstmap | Create new list by applying function |

## Technical Choices

- **Memory Safety**: All functions that allocate memory include proper NULL checks and error handling
- **String Safety**: Size-bounded functions (ft_strlcpy, ft_strlcat) prevent buffer overflows
- **Portability**: Uses size_t for sizes and unsigned char* for byte operations
- **Standard Compliance**: Functions follow the behavior and prototypes of their standard C library counterparts

## Resources

### Documentation
- [The C Programming Language (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [man pages](https://man7.org/linux/man-pages/)
- [42 Norminette Documentation](https://github.com/42School/norminette)

### AI Usage

For this project, AI was used in the following ways:
- Code review to identify edge cases
- Debugging off-by-one errors
- Assistance with README structure

## Author

Thaís Fuzita - tjulya-c
