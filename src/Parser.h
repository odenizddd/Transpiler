#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

typedef enum {
    PRIMARY = 0,
    FACTOR = 1,
    TERM = 2, 
    ASSIGNMENT = 3
} ASTType;

char* whatkind(ASTType type);

struct ASTNode{
    ASTType asttype;
    struct ASTNode* left;
    struct ASTNode* right;
    TokenType tokentype;
};
typedef struct ASTNode ASTNode;

ASTNode* newASTNode(ASTType type);

ASTNode* expression();
ASTNode* assignment();
ASTNode* term();
ASTNode* factor();
ASTNode* primary();
void show(ASTNode* node);
int eval(ASTNode* node);

#endif