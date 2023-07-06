# Get Next Line

# The goal of the project

The main goal is to develop a function that reads and retrieves the next line from a given file descriptor. 

This function should allow reading and handling multiple file descriptors, ensuring the correct behavior when reading lines of different lengths. The main objective is to create an efficient and reliable solution that correctly handles different edge cases, such as empty lines or reaching the end of a file.

## Main concepts

### Static Variable

A static variable in C is a variable that **retains its value** throughout the **entire duration of a program** and is **limited in scope** to the block or function in which it is defined. It is not destroyed when the block or function exits, allowing its value to persist across multiple function calls.

### Global Variable

A global variable in C is a variable that is defined outside of any function and can be accessed and modified by any part of the program. It has a **global scope**, meaning it is visible to all functions and blocks within the program. The value of a global variable remains persistent throughout the execution of the program.

### Difference between Global variable and Static variable?

The main difference between a global variable and a static variable in C is **their scope**.

A global variable is accessible from any part of the program and has a global scope. It can be accessed and modified by multiple functions or blocks within the program.

On the other hand, a static variable has a limited scope and is typically declared within a specific block or function. It retains its value between function calls and is not destroyed when the block or function exits. This means that the variable's value persists across different invocations of the function.

## Other concepts

### Input stream

In many programming languages, including C, input is typically read from an input stream. The input stream is a sequence of characters that represents the input source, such as the keyboard or a file.

### Standard Input

In C, the standard input stream, often referred to as stdin, represents the default input source, which is usually the keyboard. Reading from stdin allows you to obtain user input during runtime.

### Buffer

A buffer is a temporary storage space that holds data in order to smooth out or balance differences in processing speeds between two systems or components. It helps prevent bottlenecks and ensures a steady flow of data.# Get_Next_Line_Optimized
A more efficient version of the get next line function previously created. I also did the bonus, which is a version that can read from multiple file descriptors at the same time.
