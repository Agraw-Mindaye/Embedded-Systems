# Functions
The **C** language is considered to be a *functional* language
- Instructions are grouped together
- Code from one set of instructions can call other instructions
- The groups of instructions are called **functions**

#### Example
```c
int main() {
	// some code
}
```

- In the above program, there is a typical function called `main()`
- The **return type** of the function is `int`
- The parentheses`()` are for arguments (none used here)
- The curly braces `{}` tell the **compiler** to execute the instructions in between the curly braces when the function `main()` is called

### Compiling
- Compiling is the process of turning human-readable code into binary (machine code)
	- **machine code** is a bunch of 0s and 1s submitted to the CPU for execution
	- **GCC** (**GNU Compiler Collection**) is a suite of compilers commonly used

#### Example
```c
#include <stdio.h>
#include "bmp.h"

int main() {
	image 0_file;
}
```

- In the above program, the first two lines are used to signal to the compiler (**gcc**) to search for **header files**
- The first line tells gcc to look for the **stdio** (Standard Input Output) header
	- The angular brackets `<>` indicate that the standard path of the gcc installation should be searched
- The second line tells gcc to look for the `bmp.h` header file 
	- The quotation marks `""`  indicate that the current directory should be searched


# Structs

- A **Struct** is used to group data and functions

#### Example
```c
typedef struct {
	struct {
		char signature[2];
		unsigned int file_size;
	}
}
```


# Pointers

- A **pointer** is a number representing a location (**address**) in memory

#### Example
```c
File *file = fopen("red-square.bmp", "wb");
```

- `file` is a pointer to a `FILE` object
- The star `*` indicates that the variable `file` holds a memory address


# Program 
- The source code for this module is in the `code/` directory: [Source Code](./code/)

- The program creates a 24x24 pixel `BMP` file that represents the color red
  - A `BMP `file contains information on how to paint each individual pixel
  - Each pixel is represented by 3 values of RGB (Red, Green, Blue)
  - Altering these values chnages the color of the square
  - Somewhere on the `disk`, the file (e.g. 'red-square.bmp') is created containing this information
    - To do this, we need reach out to the memory on the disk, which is where we use a `pointer`