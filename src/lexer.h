#include <string>
#pragma once
enum class TokenType {
    NUMBER,
    PLUS,
    MINUS,
    IDENTIFIER,
    STAR, SLASH,
ASSIGN,
EQ, LT, GT,
LPAREN, RPAREN, LBRACE, RBRACE,
SEMICOLON,
IF, ELSE, WHILE, PRINT,INPUT,VAR,
END_OF_FILE
};
struct Token {
    TokenType type;
    std::string value;
Token () {}
    Token(TokenType t, std::string v)
        : type(t), value(v) {}
};
class Lexer
{
private:
    std::string source;
    int current;

public:
    Lexer(std::string src);

    Token getNextToken();
};