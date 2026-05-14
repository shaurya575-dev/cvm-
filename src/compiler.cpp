#include "compiler.h"

void Compiler::compile(ASTNode* node)
{
    ProgramNode* program =
    dynamic_cast<ProgramNode*>(node);
    BlockNode* block =
    dynamic_cast<BlockNode*>(node);

if (block)
{
    for (ASTNode* stmt :
         block->statements)
    {
        compile(stmt);
    }

    return;
}

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
InputNode* inputNode =
    dynamic_cast<InputNode*>(node);

if (inputNode)
{
    int slot =
        variableSlots[inputNode->name];

    bytecode.push_back(OP_INPUT);

    bytecode.push_back(slot);

    return;
}
IfNode* ifNode =
    dynamic_cast<IfNode*>(node);

if (ifNode)
{
    compile(ifNode->condition);

    bytecode.push_back(
        OP_JUMP_IF_FALSE
    );

    int jumpIndex =
        bytecode.size();

    bytecode.push_back(0);

    compile(ifNode->body);

    bytecode[jumpIndex] =
        bytecode.size();

    return;
}
WhileNode* whileNode =
    dynamic_cast<WhileNode*>(node);

if (whileNode)
{
    int loopStart =
        bytecode.size();

    compile(
        whileNode->condition
    );

    bytecode.push_back(
        OP_JUMP_IF_FALSE
    );

    int jumpIndex =
        bytecode.size();

    bytecode.push_back(0);

    compile(whileNode->body);

    bytecode.push_back(OP_JUMP);

    bytecode.push_back(loopStart);

    bytecode[jumpIndex] =
        bytecode.size();

    return;
}
AssignmentNode* assign =
    dynamic_cast<AssignmentNode*>(node);

if (assign)
{
    compile(assign->value);

    int slot =
        variableSlots[assign->name];

    bytecode.push_back(OP_STORE);

    bytecode.push_back(slot);

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
  
        else if (bin->op == "==")
{
    bytecode.push_back(OP_EQ);
}

else if (bin->op == "<")
{
    bytecode.push_back(OP_LT);
}

else if (bin->op == ">")
{
    bytecode.push_back(OP_GT);
}

        return;
    }
}