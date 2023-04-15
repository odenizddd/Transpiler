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
    int found = 0;
    for (int i = 0; i < strInt.count; i++){
        if (strcmp(char_pointer, strInt.string[i]) == 0){
            strInt.IntMap[i] = value;
            found++;
        }
    }    
    if (found == 0){
        strInt.string[strInt.count] = char_pointer;
        strInt.IntMap[strInt.count] = value;
        strInt.count++;
    }
}

int StrExists(char * char_pointer){
    for (int i = 0; i < strInt.count; i++){
        if (strcmp(char_pointer, strInt.string[i]) == 0){
            return 0;
        }
    }
    return 1;
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
    int found = 0;
    for (int i = 0; i < astStr.count ; i++){
        if (astStr.ASTMap[i] == node){
            astStr.string[i] = value;
            found++;
        }
    }
    if (found == 0){
        astStr.ASTMap[astStr.count] = node;
        astStr.string[astStr.count] = value;
        astStr.count++;
    }
}

int ASTExists(ASTNode * node){
    for (int i = 0; i < astStr.count ; i++){
        if (astStr.ASTMap[i] == node){
            return 0;
        }
    }
    return 1;
}
