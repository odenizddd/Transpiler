#include "Parser.h"

static int i = 0;

char* whatkind(ASTType type) {
    char* mykind = (char*) malloc(16 * sizeof(char));
    if(type == PRIMARY) {
        strcpy(mykind, "PRIMARY");
    }else if(type == FACTOR) {
        strcpy(mykind, "FACTOR");
    }else if(type == TERM) {
        strcpy(mykind, "TERM");
    }else if(type == ASSIGNMENT) {
        strcpy(mykind, "ASSIGNMENT");
    }else {}
    return mykind;
}

ASTNode* newASTNode(ASTType type) {
    ASTNode* node = (ASTNode*) malloc(sizeof(ASTNode));
    node->asttype = type;
    return node;
}

ASTNode* expression() {
    return term();
}

ASTNode* assignment() {
    return NULL;
}

ASTNode* term() {
    ASTNode* node = factor();
    Token token = tokens.data[i];
    while(i < tokens.count && (
        token.type == PLUS ||
        token.type == MINUS
    )) {
        i++;
        ASTNode* right = term();
        ASTNode* left = newASTNode(TERM);
        left->left = node;
        left->right = right;
        left->tokentype = token.type;
        node = left;
        token = tokens.data[i];
    }
    return node;
}

ASTNode* factor() {
    ASTNode* node = primary();
    Token token = tokens.data[i];
    while(i < tokens.count && (
        token.type == STAR ||
        token.type == DIV ||
        token.type == MODULUS
    )) {
        i++;
        ASTNode* right = primary();
        ASTNode* left = newASTNode(FACTOR);
        left->left = node;
        left->right = right;
        left->tokentype = token.type;
        node = left;
        token = tokens.data[i];
    }
    return node;
}

ASTNode* primary() {
    //TODO: implement checks when a token is consumed via i++
    Token token = tokens.data[i];
    ASTNode* primary = newASTNode(PRIMARY);
    primary->tokentype = token.type;
    if(token.type == LITERAL) {
        primary->left = (ASTNode*)token.text;
    }else if(token.type == VARIABLE) {
        primary->left = (ASTNode*)token.text;
    }else if(token.type == LEFT_PAREN) {
        i++;
        primary = expression();
    }else if(token.type == XOR ||
             token.type == LEFT_SHIFT ||
             token.type == RIGHT_SHIFT ||
             token.type == LEFT_ROT ||
             token.type == RIGHT_ROT
             ) {
        i++;
        primary->left = expression();
        i++;
        primary->right = expression();
    }else if(token.type == NOT) {
        i++;
        primary->left = expression();
    }else {error(lineNo); return NULL;}
    i++;
    return primary;
}

void show(ASTNode* node) {
    if(node->asttype == PRIMARY) {
        if(node->tokentype == LITERAL || node->tokentype == VARIABLE) {
            printf("Primary with value: %s\n", (char*)node->left);
        }else {
            printf("Primary with type: %s", whoami(node->tokentype));
            show(node->left);
            show(node->right);
        }
    }else if(node->asttype == FACTOR) {
        printf("Factor left: %s op: %s right: %s\n", whatkind(node->left->asttype), whoami(node->tokentype), whatkind(node->right->asttype));
        show(node->left);
        show(node->right);
    }else if(node->asttype == TERM) {
        printf("Term left: %s op: %s right: %s\n", whatkind(node->left->asttype), whoami(node->tokentype), whatkind(node->right->asttype));
        show(node->left);
        show(node->right);
    }else {}
}

int eval(ASTNode* node) {
    if(node->tokentype == PLUS) {
        return eval(node->left) + eval(node->right);
    }else if(node->tokentype == STAR) {
        return eval(node->left) * eval(node->right);
    }else if(node->tokentype == LITERAL){
        return atoi((char*) node->left);
    }else {return 0;}
}
