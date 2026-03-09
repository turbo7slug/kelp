#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {

    // Single-character tokens
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    SEMICOLON,

    PLUS,
    MINUS,
    STAR,
    SLASH,

    GREATER,
    LESS,
    EQUAL,

    // One or two character tokens
    EQUAL_EQUAL,
    BANG_EQUAL,
    GREATER_EQUAL,
    LESS_EQUAL,

    // Literals
    IDENTIFIER,
    NUMBER,
    STRING,

    // Keywords
    VAR,
    FUNCTION,
    IF,
    ELSE,
    RETURN,
    TRUE,
    FALSE,
    NULL_TOKEN,

    // Special
    END_OF_FILE
};

std::string tokenTypeToString(TokenType type);

struct Token {
    TokenType type;
    std::string lexeme;
    int line;

    Token(TokenType type, const std::string& lexeme, int line)
        : type(type), lexeme(lexeme), line(line) {}
};

#endif