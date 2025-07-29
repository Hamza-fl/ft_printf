# ft_printf

## Description

This project is a recreation of the standard `printf` function from the C standard library.  It aims to provide the same functionality, allowing formatted output to the standard output stream.

## Features and Functionality

*   **Formatted Output:** Supports formatted printing of various data types including characters, strings, integers (decimal, hexadecimal, octal), and pointers.
*   **Conversion Specifiers:** Implements the following conversion specifiers:
    *   `c`: Character
    *   `s`: String
    *   `d` or `i`: Signed decimal integer
    *   `u`: Unsigned decimal integer
    *   `x`: Unsigned hexadecimal integer (lowercase)
    *   `X`: Unsigned hexadecimal integer (uppercase)
    *   `p`: Pointer address
    *   `%`: Percent sign

*   **Error Handling:** Handles potential errors and returns the correct number of characters printed.

## Technology Stack

*   **C Programming Language:** The project is implemented entirely in C.

## Prerequisites

*   **GCC Compiler:** You need a C compiler, such as GCC, to compile the project.
*   **Make:**  A `Makefile` is provided for easy compilation.

## Installation Instructions

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/Hamza-fl/ft_printf
    cd ft_printf
    ```

2.  **Compile the Library:**
    ```bash
    make
    ```
    This will create a static library `libftprintf.a`.

## Usage Guide

1.  **Include the Header File:** In your C program, include the `ft_printf.h` header file:
    ```c
    #include "ft_printf.h"
    ```

2.  **Link the Library:**  When compiling your program, link the `libftprintf.a` library.  For example:
    ```bash
    gcc your_program.c -L. -lftprintf -o your_program
    ```
    (assuming `libftprintf.a` is in the current directory).

3.  **Use `ft_printf`:** Call `ft_printf` with the desired format string and arguments, just like the standard `printf`.  For example:
    ```c
    #include "ft_printf.h"
    #include <stdio.h> // For comparison purposes

    int main() {
        int num = 42;
        char *str = "Hello, world!";
        void *ptr = &num;

        ft_printf("ft_printf: Integer: %d, String: %s, Pointer: %p\n", num, str, ptr);
        printf("printf: Integer: %d, String: %s, Pointer: %p\n", num, str, ptr);

        return 0;
    }
    ```
