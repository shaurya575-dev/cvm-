README.md
# CVM++

CVM++ is a custom scripting language and stack-based virtual machine written in C++.

This project includes:

- Lexer
- Parser
- Abstract Syntax Tree (AST)
- Bytecode Compiler
- Stack Virtual Machine (VM)

The language supports variables, arithmetic, conditions, loops, input/output, and execution from `.cvm` source files.

---

# Features

## Variables

```c
var x = 10;
ARITHMETIC
print(x);
print(10 + 5);
print(10 - 5);
print(10 * 5);
print(10 / 5);
COMPARISONS
print(10 > 5);
print(10 < 5);
print(10 == 10);
ASSIGNMENT
var x = 5;

x = 20;

print(x);
IF STATEMENTS
if (10 > 5)
{
    print(999);
}
WHILE LOOPS
var x = 0;

while (x < 5)
{
    print(x);

    x = x + 1;
}
INPUT OUTPUT
var x = 0;

input(x);

print(x);
PROJECT STRUCTURE
CVM++
│
├── src
│   ├── lexer.cpp
│   ├── lexer.h
│   ├── parser.cpp
│   ├── parser.h
│   ├── compiler.cpp
│   ├── compiler.h
│   ├── vm.cpp
│   ├── vm.h
│   └── main.cpp
│
├── tests
│   └── hello.cvm
│
└── README.md
How It Works
1. Lexer

The lexer converts source code into tokens.

Example:

var x = 10;

becomes:

VAR IDENTIFIER ASSIGN NUMBER SEMICOLON
2. Parser

The parser converts tokens into an AST (Abstract Syntax Tree).

3. Compiler

The compiler converts the AST into bytecode instructions.

Example:

OP_PUSH
OP_ADD
OP_PRINT
4. Virtual Machine

The VM executes bytecode using a stack-based architecture.

Build

Compile using g++:

g++ src/main.cpp src/lexer.cpp src/parser.cpp src/compiler.cpp src/vm.cpp -o main
Run
.\main
Example Program
var x = 0;

while (x < 5)
{
    print(x);

    x = x + 1;
}

var y = 0;

input(y);

print(y);
Example Output
0
1
2
3
4
25
Technologies Used
C++
Object Oriented Programming
Recursive Descent Parsing
Stack-Based Virtual Machine
Bytecode Compilation
Future Improvements

Possible future features:

Functions
Strings
Arrays
Booleans
Garbage Collection
Better Error Handling
Comments
Standard Library
File I/O
Author

Shaurya
License

This project is open source and free to use.


