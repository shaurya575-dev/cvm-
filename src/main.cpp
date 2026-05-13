#include <iostream>

#include "lexer.h"
#include "parser.h"

int main()
{

    Lexer lexer("(10 + 20) * 3");

    Parser parser(lexer);

    ASTNode* tree = parser.parse();

    int result = evaluate(tree);

    std::cout << result << std::endl;
Token t = lexer.getNextToken();

while (t.type != TokenType::END_OF_FILE)
{
    std::cout << t.value << std::endl;

    t = lexer.getNextToken();
}
    return 0;
}