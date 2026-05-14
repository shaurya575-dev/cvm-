# CVM++

A custom scripting language and virtual machine written in C++.

## Features

- Variables
- Arithmetic
- Comparisons
- if statements
- while loops
- Input / Output
- Bytecode compiler
- Stack virtual machine

## Example

```c
var x = 0;

while (x < 5)
{
    print(x);

    x = x + 1;
}
g++ src/main.cpp src/lexer.cpp src/parser.cpp src/compiler.cpp src/vm.cpp -o main
.\main

Then push again:

```bash id="f2w7rn"
git add .
git commit -m "Add README"
git push
