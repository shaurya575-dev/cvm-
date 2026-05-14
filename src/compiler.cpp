#include "compiler.h"

void Compiler::compile(ASTNode* node)
{
    ProgramNode* program =
    dynamic_cast<ProgramNode*>(node);

if (program)
{
    for (ASTNode* stmt :
         program->statements)
    {
        compile(stmt);
    }

    return;
}
    NumberNode* number =
        dynamic_cast<NumberNode*>(node);

    if (number)
    {
        bytecode.push_back(OP_PUSH);

        bytecode.push_back(
            std::stoi(number->value)
        );

        return;
    }
VariableNode* variable =
    dynamic_cast<VariableNode*>(node);

if (variable)
{
    int slot =
        variableSlots[variable->name];

    bytecode.push_back(OP_LOAD);

    bytecode.push_back(slot);

    return;
}
VarDeclNode* varDecl =
    dynamic_cast<VarDeclNode*>(node);

if (varDecl)
{
    compile(varDecl->value);

    int slot = nextSlot;

    variableSlots[varDecl->name] =
        slot;

    nextSlot++;

    bytecode.push_back(OP_STORE);

    bytecode.push_back(slot);

    return;
}
PrintNode* printNode =
    dynamic_cast<PrintNode*>(node);

if (printNode)
{
    compile(printNode->expression);

    bytecode.push_back(OP_PRINT);

    return;
}
    BinaryOpNode* bin =
        dynamic_cast<BinaryOpNode*>(node);

    if (bin)
    {
        compile(bin->left);

        compile(bin->right);

        if (bin->op == "+")
        {
            bytecode.push_back(OP_ADD);
        }

        else if (bin->op == "-")
        {
            bytecode.push_back(OP_SUB);
        }

        else if (bin->op == "*")
        {
            bytecode.push_back(OP_MUL);
        }

        else if (bin->op == "/")
        {
            bytecode.push_back(OP_DIV);
        }

        return;
    }
}