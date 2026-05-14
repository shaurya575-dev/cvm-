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
OP_INPUT,
OP_PRINT,
OP_EQ,
OP_LT,
OP_GT,
OP_JUMP_IF_FALSE,
OP_JUMP,
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