#include "token.h"

std::string tokenTypeToString(TokenType type) {

    switch (type) {

        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::SEMICOLON: return "SEMICOLON";

        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::STAR: return "STAR";
        case TokenType::SLASH: return "SLASH";

        case TokenType::GREATER: return "GREATER";
        case TokenType::LESS: return "LESS";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";

        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::STRING: return "STRING";

        case TokenType::VAR: return "VAR";
        case TokenType::FUNCTION: return "FUNCTION";
        case TokenType::IF: return "IF";
        case TokenType::ELSE: return "ELSE";
        case TokenType::RETURN: return "RETURN";
        case TokenType::TRUE: return "TRUE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::NULL_TOKEN: return "NULL";

        case TokenType::END_OF_FILE: return "EOF";
    }

    return "UNKNOWN";
}