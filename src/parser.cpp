#include "parser.h"
#include <iostream>
Parser::Parser(Lexer lex)
    : lexer(lex)
{
    currentToken = lexer.getNextToken();
}
    ASTNode* Parser::parse()
{
    return parseExpression();
}
ASTNode* Parser::parseFactor()
{
    if (currentToken.type == TokenType::NUMBER)
    {
        ASTNode* node =
            new NumberNode(currentToken.value);

        currentToken = lexer.getNextToken();

        return node;
    }

    if (currentToken.type == TokenType::LPAREN)
    {
        currentToken = lexer.getNextToken();

        ASTNode* node = parseExpression();

        if (currentToken.type == TokenType::RPAREN)
        {
            currentToken = lexer.getNextToken();

            return node;
        }
    }

    return NULL;
}


    ASTNode* Parser::parseTerm()
{
    ASTNode* left = parseFactor();

    while (
        currentToken.type == TokenType::STAR ||
        currentToken.type == TokenType::SLASH
    )
    {
        std::string op = currentToken.value;

        currentToken = lexer.getNextToken();

        ASTNode* right = parseFactor();

        left = new BinaryOpNode(op, left, right);
    }

    return left;
}

ASTNode* Parser::parseExpression()
{
   // if (currentToken.type != TokenType::NUMBER)
  // {
   //     return NULL;
   // }

    ASTNode* left = parseTerm();

  while (
    currentToken.type == TokenType::PLUS ||
    currentToken.type == TokenType::MINUS
)
{
    std::string op = currentToken.value;

    currentToken = lexer.getNextToken();

    ASTNode* right = parseTerm();

    left = new BinaryOpNode(op, left, right);
}

    return left;
}
int evaluate(ASTNode* node)
{
    NumberNode* number =
        dynamic_cast<NumberNode*>(node);

    if (number)
    {
        return std::stoi(number->value);
    }

    BinaryOpNode* bin =
        dynamic_cast<BinaryOpNode*>(node);

    if (bin)
    {
        int leftValue = evaluate(bin->left);

        int rightValue = evaluate(bin->right);

        if (bin->op == "+")
{
    return leftValue + rightValue;
}

if (bin->op == "-")
{
    return leftValue - rightValue;
}

if (bin->op == "*")
{
    return leftValue * rightValue;
}

if (bin->op == "/")
{
    return leftValue / rightValue;
}
    }

    return 0;
}
