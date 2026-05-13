#include <iostream>
#include "lexer.h"

int main()
{
    Lexer lexer("varx + total");

    Token t = lexer.getNextToken();

    while (t.type != TokenType::END_OF_FILE)
    {
        std::cout << t.value << std::endl;

        t = lexer.getNextToken();
    }

    return 0;
}