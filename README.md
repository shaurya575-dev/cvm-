# Stack-Based Virtual Machine & Custom Compiler

A miniature programming language implemented in C++.

## Features

- Lexer / Tokenizer
- Recursive Descent Parser
- Abstract Syntax Tree (AST)
- Bytecode Compiler
- Stack-Based Virtual Machine
- Variables
- Arithmetic Expressions
- Print Statements
- Multiple Statements

## Example Program

```c
var x = 10;
print(x);

var y = 20;
print(y);

print(x + y);
print((x + y) * 2);
```

## Expected Output

```text
10
20
30
60
```

## Architecture

Source Code
→ Lexer
→ Parser
→ AST
→ Compiler
→ Bytecode
→ Virtual Machine

## Build

```bash
g++ main.cpp lexer.cpp parser.cpp compiler.cpp vm.cpp -o main
```

## Run

```bash
.\main
```

## Project Structure

```text
src/
tests/
README.md
```
