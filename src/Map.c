#include "map.h"

StrInt strInt = {.count = 0};
AstStr astStr = {.count = 0};

int getInt(char * char_pointer){
    for (int i = 0; i < strInt.count; i++){
        if (strcmp(char_pointer, strInt.string[i]) == 0){
            return strInt.IntMap[i];
        }
    }
    return -1;
}

void setInt(int index, int value){
    strInt.IntMap[index] = value;
}

int StrExists(char * char_pointer){
    for (int i = 0; i < strInt.count; i++){
        if (strcmp(char_pointer, strInt.string[i]) == 0){
            return 0;
        }
    }
    return -1;
}

char *getString(ASTNode * node){
    for (int i = 0; i < astStr.count ; i++){
        if (astStr.ASTMap[i] == node){
            return astStr.string[i];
        }
    }
    return -1;
}

void setString(int index, char * value){
    astStr.string[index] = value;
}

int ASTExists(ASTNode * node){
    for (int i = 0; i < astStr.count ; i++){
        if (astStr.ASTMap[i] == node){
            return 0;
        }
    }
    return -1;
}
