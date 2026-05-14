#include <iostream>

#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "vm.h"

int main()
{
    std::string source =
        "var x = 10; "
        "print(x); "
        "print(x + 5);";

    Lexer lexer(source);

    Parser parser(lexer);

    ASTNode* tree = parser.parse();

    Compiler compiler;

    compiler.compile(tree);

    compiler.bytecode.push_back(OP_HALT);

    VM vm;

    vm.run(compiler.bytecode);

    return 0;
}