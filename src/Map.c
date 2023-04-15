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

void setInt(char * char_pointer, int value){
    for (int i = 0; i < strInt.count; i++){
        if (strcmp(char_pointer, strInt.string[i]) == 0){
            strInt.IntMap[i] = value;
        }
    }    
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

void setString(ASTNode * node, char * value){
    for (int i = 0; i < astStr.count ; i++){
        if (astStr.ASTMap[i] == node){
            astStr.string[i] = value;
        }
    }
}

int ASTExists(ASTNode * node){
    for (int i = 0; i < astStr.count ; i++){
        if (astStr.ASTMap[i] == node){
            return 0;
        }
    }
    return -1;
}
