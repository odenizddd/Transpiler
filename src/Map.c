#include "map.h"

int getInt(char * char_pointer, StrInt map){
    for (int i = 0; i < map.count; i++){
        if (strcmp(char_pointer, map.string[i]) == 0){
            return map.IntMap[i];
        }
    }
    return -1;
}

void setInt(int index, int value, StrInt map){
    map.IntMap[index] = value;
}

int StrExists(char * char_pointer, StrInt map){
    for (int i = 0; i < map.count; i++){
        if (strcmp(char_pointer, map.string[i]) == 0){
            return 0;
        }
    }
    return -1;
}

char *getString(ASTNode * node, AstStr map){
    for (int i = 0; i < map.count ; i++){
        if ((& map.ASTMap[i]) == (& node)){
            return map.string[i];
        }
    }
}

void setString(int index, char * value, AstStr map){
    map.string[index] = value;
}

int ASTExists(ASTNode * node, AstStr map){
    for (int i = 0; i < map.count ; i++){
        if ((& map.ASTMap[i]) == (& node)){
            return 0;
        }
    }
    return -1;
}
