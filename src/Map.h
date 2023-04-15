#ifndef MAP_H
#define MAP_H

#include "Parser.h"

static struct StrInt{
    char *string[512];
    int IntMap[512];
    int count;  
};
static struct StrInt StrInt;

static struct AstStr{
    ASTNode *ASTMap[512];
    char *string[512];
    int count;
};
static struct AstStr AstStr;

int getInt(char *);
void setInt(int, int);
int StrExists(char *);

char *getString(ASTNode *);
void setString(int, char *);
int ASTExists(ASTNode *);

#endif
