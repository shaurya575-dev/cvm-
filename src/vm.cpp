#include "vm.h"
#include <iostream>
int VM::run(std::vector<int> bytecode)
{
    int ip = 0;

    while (true)
    {
        int instruction = bytecode[ip];

        if (instruction == OP_PUSH)
        {
            ip++;

            int value = bytecode[ip];

            stack.push_back(value);
        }

        else if (instruction == OP_ADD)
        {
            int right = stack.back();
            stack.pop_back();

            int left = stack.back();
            stack.pop_back();

            stack.push_back(left + right);
        }

        else if (instruction == OP_SUB)
        {
            int right = stack.back();
            stack.pop_back();

            int left = stack.back();
            stack.pop_back();

            stack.push_back(left - right);
        }

        else if (instruction == OP_MUL)
        {
            int right = stack.back();
            stack.pop_back();

            int left = stack.back();
            stack.pop_back();

            stack.push_back(left * right);
        }

        else if (instruction == OP_DIV)
        {
            int right = stack.back();
            stack.pop_back();

            int left = stack.back();
            stack.pop_back();

            stack.push_back(left / right);
        }
        else if (instruction == OP_EQ)
{
    int right = stack.back();
    stack.pop_back();

    int left = stack.back();
    stack.pop_back();

    stack.push_back(left == right);
}

else if (instruction == OP_LT)
{
    int right = stack.back();
    stack.pop_back();

    int left = stack.back();
    stack.pop_back();

    stack.push_back(left < right);
}

else if (instruction == OP_GT)
{
    int right = stack.back();
    stack.pop_back();

    int left = stack.back();
    stack.pop_back();

    stack.push_back(left > right);
}
else if (instruction == OP_STORE)
{
    ip++;

    int slot = bytecode[ip];

    int value = stack.back();

    stack.pop_back();

    variables[slot] = value;
}

else if (instruction == OP_LOAD)
{
    ip++;

    int slot = bytecode[ip];

    stack.push_back(
        variables[slot]
    );
}
else if (instruction == OP_INPUT)
{
    ip++;

    int slot =
        bytecode[ip];

    int value;

    std::cin >> value;

    variables[slot] = value;
}
else if (instruction == OP_PRINT)
{
    int value = stack.back();

    stack.pop_back();

    std::cout << value << std::endl;
}
else if (instruction == OP_JUMP_IF_FALSE)
{
    ip++;

    int target = bytecode[ip];

    int condition = stack.back();

    stack.pop_back();

    if (condition == 0)
   {
    ip =target;
    continue;
   }
}
else if (instruction == OP_JUMP)
{
    ip++;

    int target =
        bytecode[ip];

    ip = target;

    continue;
}
else if (instruction == OP_JUMP)
{
    ip++;

    int target =
        bytecode[ip];

    ip = target;

    continue;
}
        else if (instruction == OP_HALT)
        {
            return 0;
        }

        ip++;
    }
}