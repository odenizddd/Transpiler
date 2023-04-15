#include "map.h"

int getInt(char * char_pointer){
    for (int i = 0; i < StrInt.count; i++){
        if (strcmp(char_pointer, StrInt.string[i]) == 0){
            return StrInt.IntMap[i];
        }
    }
    return -1;
}

void setInt(int index, int value){
    StrInt.IntMap[index] = value;
}

int StrExists(char * char_pointer){
    for (int i = 0; i < StrInt.count; i++){
        if (strcmp(char_pointer, StrInt.string[i]) == 0){
            return 0;
        }
    }
    return -1;
}

char *getString(ASTNode * node){
    for (int i = 0; i < AstStr.count ; i++){
        if (AstStr.ASTMap[i] == node){
            return AstStr.string[i];
        }
    }
    return -1;
}

void setString(int index, char * value){
    AstStr.string[index] = value;
}

int ASTExists(ASTNode * node){
    for (int i = 0; i < AstStr.count ; i++){
        if (AstStr.ASTMap[i] == node){
            return 0;
        }
    }
    return -1;
}
