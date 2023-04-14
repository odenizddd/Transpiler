#ifndef MAP_H
#define MAP_H

#include "Parser.h"

struct StrInt{
    char *string[512];
    int IntMap[512];
    int count;  
};
typedef struct StrInt StrInt;

struct AstStr{
    ASTNode *ASTMap[512];
    char *string[512];
    int count;
};
typedef struct AstStr AstStr;

int getInt(char *, StrInt);
void setInt(int, int, StrInt);
int StrExists(char *, StrInt);

char *getString(ASTNode *, AstStr);
void setString(int, char *, AstStr);
int ASTExists(ASTNode *, AstStr);

#endif
