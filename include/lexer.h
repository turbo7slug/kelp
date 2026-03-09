#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "token.h"

class Lexer {

public:
    explicit Lexer(const std::string& source);

    std::vector<Token> scanTokens();

private:

    std::string source;
    std::vector<Token> tokens;

    int start = 0;
    int current = 0;
    int line = 1;

    bool isAtEnd();
    char advance();
    bool match(char expected);
    void addToken(TokenType type);
    
    char peek();
    char peekNext();

    void scanToken();

    void number();
    void identifier();
    void string();
};

#endif