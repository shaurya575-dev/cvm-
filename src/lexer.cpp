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

if (ch == '=')
{
    current++;
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
if (ch == ';')
{
    current++;

    return Token(
        TokenType::SEMICOLON,
        ";"
    );
}
return Token(TokenType::END_OF_FILE, "");
}
