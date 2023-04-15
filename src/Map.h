#ifndef MAP_H
#define MAP_H

#include "Parser.h"

typedef struct{
    char *string[512];
    int IntMap[512];
    int count;  
} StrInt;

extern StrInt strInt;

typedef struct{
    ASTNode *ASTMap[512];
    char *string[512];
    int count;
} AstStr;

extern AstStr astStr;

int getInt(char *);
void setInt(int, int);
int StrExists(char *);

char *getString(ASTNode *);
void setString(int, char *);
int ASTExists(ASTNode *);

#endif
