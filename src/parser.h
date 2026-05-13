#pragma once

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
};
int evaluate(ASTNode* node);
class VariableNode : public ASTNode
{
public:
    std::string name;

    VariableNode(std::string n)
        : name(n) {}
};