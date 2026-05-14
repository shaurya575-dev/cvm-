#pragma once

#include <vector>

#include "parser.h"
#include "vm.h"
#include <unordered_map>
class Compiler
{
public:
    std::vector<int> bytecode;
std::unordered_map<std::string, int> variableSlots;

int nextSlot = 0;
    void compile(ASTNode* node);
};