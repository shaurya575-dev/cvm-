#include <iostream>
#include <fstream>
#include <sstream>

#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "vm.h"

int main()
{
    std::ifstream file("tests/hello.cvm");

    std::stringstream buffer;

    buffer << file.rdbuf();

    std::string source = buffer.str();

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