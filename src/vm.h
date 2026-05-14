#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>

enum OpCode
{
    OP_PUSH,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_STORE,
OP_LOAD,
OP_PRINT,
    OP_HALT
};
class VM
{
private:
    std::vector<int> stack;
    std::unordered_map<int, int> variables;

public:
    int run(std::vector<int> bytecode);
};