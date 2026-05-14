#include "parser.h"
#include <iostream>
#include <unordered_map>
std::unordered_map<std::string, int> variables;
Parser::Parser(Lexer lex)
    : lexer(lex)
{
    currentToken = lexer.getNextToken();
}
   ASTNode* Parser::parse()
{
    ProgramNode* program =
        new ProgramNode();

    while (
        currentToken.type !=
        TokenType::END_OF_FILE
    )
    {
        program->statements.push_back(
            parseStatement()
        );
    }

    return program;
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
if (currentToken.type ==
    TokenType::IDENTIFIER)
{
    ASTNode* node =
        new VariableNode(
            currentToken.value
        );

    currentToken =
        lexer.getNextToken();

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
ASTNode* Parser::parseStatement()
{
    if (currentToken.type == TokenType::VAR)
    {
        currentToken = lexer.getNextToken();

        std::string name =
            currentToken.value;

        currentToken =
            lexer.getNextToken();

        currentToken =
            lexer.getNextToken();

        ASTNode* value =
            parseExpression();

        currentToken =
            lexer.getNextToken();

        return new VarDeclNode(
            name,
            value
        );
    }

    if (currentToken.type ==
        TokenType::PRINT)
    {
        currentToken =
            lexer.getNextToken();

        currentToken =
            lexer.getNextToken();

        ASTNode* expr =
            parseExpression();

        currentToken =
            lexer.getNextToken();

        currentToken =
            lexer.getNextToken();

        return new PrintNode(expr);
    }
if (currentToken.type ==
    TokenType::INPUT)
{
    currentToken =
        lexer.getNextToken();

    currentToken =
        lexer.getNextToken();

    std::string name =
        currentToken.value;

    currentToken =
        lexer.getNextToken();

    currentToken =
        lexer.getNextToken();

    currentToken =
        lexer.getNextToken();

    return new InputNode(name);
}
    if (currentToken.type ==
        TokenType::IF)
    {
        currentToken =
            lexer.getNextToken();

        if (currentToken.type ==
            TokenType::LPAREN)
        {
            currentToken =
                lexer.getNextToken();
        }

        ASTNode* condition =
            parseExpression();

        if (currentToken.type ==
            TokenType::RPAREN)
        {
            currentToken =
                lexer.getNextToken();
        }

        ASTNode* body;

        if (currentToken.type ==
            TokenType::LBRACE)
        {
            body = parseBlock();
        }
        else
        {
            body = parseStatement();
        }

        return new IfNode(
            condition,
            body
        );
    }
 if (currentToken.type ==
    TokenType::WHILE)
{
    currentToken =
        lexer.getNextToken();

    if (currentToken.type ==
        TokenType::LPAREN)
    {
        currentToken =
            lexer.getNextToken();
    }

    ASTNode* condition =
        parseExpression();

    if (currentToken.type ==
        TokenType::RPAREN)
    {
        currentToken =
            lexer.getNextToken();
    }

    ASTNode* body;

    if (currentToken.type ==
        TokenType::LBRACE)
    {
        body = parseBlock();
    }
    else
    {
        body = parseStatement();
    }

    return new WhileNode(
        condition,
        body
    );
}
    if (currentToken.type ==
        TokenType::IDENTIFIER)
    {
        std::string name =
            currentToken.value;

        currentToken =
            lexer.getNextToken();

        if (currentToken.type ==
            TokenType::ASSIGN)
        {
            currentToken =
                lexer.getNextToken();

            ASTNode* value =
                parseExpression();

            if (currentToken.type ==
                TokenType::SEMICOLON)
            {
                currentToken =
                    lexer.getNextToken();
            }

            return new AssignmentNode(
                name,
                value
            );
        }
    }

    ASTNode* expr =
        parseExpression();

    if (currentToken.type ==
        TokenType::SEMICOLON)
    {
        currentToken =
            lexer.getNextToken();
    }

    return expr;
}
 ASTNode* Parser::parseBlock()
{
    BlockNode* block =
        new BlockNode();

    if (currentToken.type ==
        TokenType::LBRACE)
    {
        currentToken =
            lexer.getNextToken();
    }

    while (
        currentToken.type !=
        TokenType::RBRACE
    )
    {
        block->statements.push_back(
            parseStatement()
        );
    }

    currentToken =
        lexer.getNextToken();

    return block;
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
    currentToken.type == TokenType::MINUS ||
    currentToken.type == TokenType::EQ ||
    currentToken.type == TokenType::LT ||
    currentToken.type == TokenType::GT
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
VariableNode* variable =
    dynamic_cast<VariableNode*>(node);

if (variable)
{
    return variables[variable->name];
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
if (bin->op == "==")
{
    return leftValue == rightValue;
}

if (bin->op == "<")
{
    return leftValue < rightValue;
}

if (bin->op == ">")
{
    return leftValue > rightValue;
}
    }
VarDeclNode* varDecl =
    dynamic_cast<VarDeclNode*>(node);

if (varDecl)
{
    int value = evaluate(varDecl->value);

    variables[varDecl->name] = value;

    return value;
}
    return 0;
}
