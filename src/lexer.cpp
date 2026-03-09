#include "lexer.h"
#include <unordered_map>
#include <cctype>

Lexer::Lexer(const std::string& source) : source(source) {}

bool Lexer::isAtEnd() {
    return current >= source.length();
}

char Lexer::advance() {
    return source[current++];
}

bool Lexer::match(char expected) {

    if (isAtEnd()) return false;

    if (source[current] != expected) return false;

    current++;
    return true;
}

void Lexer::addToken(TokenType type) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, text, line);
}

std::vector<Token> Lexer::scanTokens() {

    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    tokens.emplace_back(TokenType::END_OF_FILE, "", line);
    return tokens;
}

void Lexer::scanToken() {

    char c = advance();

    switch (c) {

        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;

        case ')':
            addToken(TokenType::RIGHT_PAREN);
            break;

        case '{':
            addToken(TokenType::LEFT_BRACE);
            break;

        case '}':
            addToken(TokenType::RIGHT_BRACE);
            break;

        case ',':
            addToken(TokenType::COMMA);
            break;

        case ';':
            addToken(TokenType::SEMICOLON);
            break;

        case '+':
            addToken(TokenType::PLUS);
            break;

        case '-':
            addToken(TokenType::MINUS);
            break;

        case '*':
            addToken(TokenType::STAR);
            break;

        case '/':
            if (match('/')) {
            // consume characters until end of line
            while (peek() != '\n' && !isAtEnd()) {
            advance();
        }
    } else {
        addToken(TokenType::SLASH);
    }
    break;

        case '"':
            string();
            break;

        case '>':
            if (match('=')) {
            addToken(TokenType::GREATER_EQUAL);
            }    
            else {
            addToken(TokenType::GREATER);
            }
            break;

        case '<':
            if (match('=')) {
            addToken(TokenType::LESS_EQUAL);
            }    
            else {
            addToken(TokenType::LESS);
            }
            break;

        case '=':
        if (match('=')) {
        addToken(TokenType::EQUAL_EQUAL);
        }
        else {
        addToken(TokenType::EQUAL);
        }
            break;

        case '!':
            if (match('=')) {
            addToken(TokenType::BANG_EQUAL);
            }       
            break;

        case ' ':
        case '\r':
        case '\t':
            break;

        case '\n':
            line++;
            break;

        default:

            if (isdigit(c)) {
                number();
            }
            else if (isalpha(c)) {
                identifier();
            }
            break;
    }
}

void Lexer::number() {

    while (isdigit(peek())) {
        advance();
    }

    // check for decimal point
    if (peek() == '.' && isdigit(peekNext())) {

        advance(); // consume '.'

        while (isdigit(peek())) {
            advance();
        }
    }

    addToken(TokenType::NUMBER);
}

void Lexer::identifier() {

    while (!isAtEnd() && isalnum(source[current])) {
        advance();
    }

    std::string text = source.substr(start, current - start);

    static std::unordered_map<std::string, TokenType> keywords = {
        {"var", TokenType::VAR},
        {"function", TokenType::FUNCTION},
        {"if", TokenType::IF},
        {"else", TokenType::ELSE},
        {"return", TokenType::RETURN},
        {"true", TokenType::TRUE},
        {"false", TokenType::FALSE},
        {"null", TokenType::NULL_TOKEN}
    };

    if (keywords.find(text) != keywords.end()) {
        addToken(keywords[text]);
    } else {
        addToken(TokenType::IDENTIFIER);
    }
}

void Lexer::string() {

    while (!isAtEnd() && source[current] != '"') {

        if (source[current] == '\n') {
            line++;
        }

        advance();
    }

    if (isAtEnd()) {
        // unterminated string
        return;
    }

    // consume closing quote
    advance();

    addToken(TokenType::STRING);
}

char Lexer::peek() {
    if (isAtEnd()) return '\0';
    return source[current];
}

char Lexer::peekNext() {
    if (current + 1 >= source.length()) return '\0';
    return source[current + 1];
}