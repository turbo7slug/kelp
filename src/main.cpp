#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: kelp <script.js>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer(source);
    auto tokens = lexer.scanTokens();
    
for (const auto& token : tokens) {
    std::cout << tokenTypeToString(token.type)
              << "    "
              << token.lexeme
              << std::endl;
}

    return 0;
}