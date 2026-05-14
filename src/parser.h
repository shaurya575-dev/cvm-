#pragma once
#include <vector>
#include "lexer.h"

class ASTNode
{
public:
    virtual ~ASTNode() = default;
};
class NumberNode : public ASTNode
{
public:
    std::string value;

    NumberNode(std::string val)
        : value(val) {}
};
class VariableNode : public ASTNode
{
public:
    std::string name;

    VariableNode(std::string n)
        : name(n) {}
};
class BinaryOpNode : public ASTNode
{
public:
    std::string op;

    ASTNode* left;
    ASTNode* right;

    BinaryOpNode(std::string oper, ASTNode* l, ASTNode* r)
        : op(oper), left(l), right(r) {}
};
class Parser
{
private:
    Lexer lexer;
    Token currentToken;

public:
    Parser(Lexer lex);

    ASTNode* parse();
    ASTNode* parseExpression();
    ASTNode* parseFactor();
    ASTNode* parseTerm();
    ASTNode* parseStatement();
    ASTNode* parseBlock();
};
int evaluate(ASTNode* node);
class VarDeclNode : public ASTNode
{
public:
    std::string name;
    ASTNode* value;

    VarDeclNode(std::string n, ASTNode* v)
        : name(n), value(v) {}
};
class AssignmentNode : public ASTNode
{
public:
    std::string name;
    ASTNode* value;

    AssignmentNode(
        std::string n,
        ASTNode* v
    )
    {
        name = n;
        value = v;
    }
};
class PrintNode : public ASTNode
{
public:
    ASTNode* expression;

    PrintNode(ASTNode* expr)
        : expression(expr) {}
};
class InputNode : public ASTNode
{
public:
    std::string name;

    InputNode(std::string n)
    {
        name = n;
    }
};
class IfNode : public ASTNode
{
public:
    ASTNode* condition;
    ASTNode* body;

    IfNode(
        ASTNode* cond,
        ASTNode* stmt
    )
        : condition(cond),
          body(stmt)
    {
    }
};
class WhileNode : public ASTNode
{
public:
    ASTNode* condition;
    ASTNode* body;

    WhileNode(
        ASTNode* cond,
        ASTNode* bod
    )
    {
        condition = cond;
        body = bod;
    }
};
class BlockNode : public ASTNode
{
public:
    std::vector<ASTNode*> statements;
};
class ProgramNode : public ASTNode
{
public:
    std::vector<ASTNode*> statements;
};