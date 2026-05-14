#include "lexer.h"
#include <cctype>
Lexer::Lexer(std::string src)
    : source(src), current(0)
{
}
Token Lexer::getNextToken()
{
    char ch = source[current];
    while (isspace(ch))
{
    current++;
    ch = source[current];
}

   if (isdigit(ch))
{
    std::string number;

    while (isdigit(source[current]))
    {
        number += source[current];
        current++;
    }

    return Token(TokenType::NUMBER, number);
}
if (isalpha(ch))
{
    std::string identifier;

    while (isalnum(source[current]))
    {
        identifier += source[current];
        current++;
    }

if (identifier == "var")
{
    return Token(TokenType::VAR, identifier);
}

if (identifier == "print")
{
    return Token(TokenType::PRINT, identifier);
}
if (identifier == "input")
{
    return Token(
        TokenType::INPUT,
        identifier
    );
}
if (identifier == "while")
{
    return Token(TokenType::WHILE, identifier);
}
if (identifier == "if")
{
    return Token(
        TokenType::IF,
        identifier
    );
}

return Token(TokenType::IDENTIFIER, identifier);
}
    if (ch == '+')
    {
        current++;

        return Token(TokenType::PLUS, "+");
    }
    if (ch == '-')
{
    current++;
    return Token(TokenType::MINUS, "-");
}

if (ch == '*')
{
    current++;
    return Token(TokenType::STAR, "*");
}

if (ch == '/')
{
    current++;
    return Token(TokenType::SLASH, "/");
}

//if (ch == '=')
//{
  //  current++;
  //  return Token(TokenType::ASSIGN, "=");
//}
if (ch == '=')
{
    current++;

    if (source[current] == '=')
    {
        current++;

        return Token(TokenType::EQ, "==");
    }

    return Token(TokenType::ASSIGN, "=");
}

if (source[current] == '(')
{
    current++;

    return Token(TokenType::LPAREN, "(");
}

if (source[current] == ')')
{
    current++;

    return Token(TokenType::RPAREN, ")");
}
if (source[current] == '{')
{
    current++;

    return Token(TokenType::LBRACE, "{");
}

if (source[current] == '}')
{
    current++;

    return Token(TokenType::RBRACE, "}");
}
if (ch == ';')
{
    current++;

    return Token(
        TokenType::SEMICOLON,
        ";"
    );
}
if (ch == '<')
{
    current++;

    return Token(TokenType::LT, "<");
}
if (ch == '>')
{
    current++;

    return Token(TokenType::GT, ">");
}
if (ch == '=')
{
    current++;

    if (source[current] == '=')
    {
        current++;

        return Token(TokenType::EQ, "==");
    }

    return Token(TokenType::ASSIGN, "=");
}
return Token(TokenType::END_OF_FILE, "");
}
