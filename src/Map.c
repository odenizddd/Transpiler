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
        // Return the ASTNode if they are equal.
        // Is there a function which returns whether two ASTNodes are equal to each other?
    }
}

void setString(int index, char * value, AstStr map){
    map.string[index] = value;
}

int ASTExists(ASTNode * node, AstStr map){
    for (int i = 0; i < map.count ; i++){
        // Return 0 if they are equal.
        // Is there a function which returns whether two ASTNodes are equal to each other?
    }
    return -1;
}
