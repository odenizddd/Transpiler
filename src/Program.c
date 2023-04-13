#include "Program.h"

int lineNo = 1;

void transpile(char* path) {
    FILE* file;
    size_t len = 128;
    char* line = (char*) malloc(len * sizeof(char));

    file = fopen(path, "r");
    
    while(getline(&line, &len, file) != -1) {
        tokenize(line);
        if(safe(lineNo)) {
            ASTNode* root = expression();
            show(root);
            if(safe(lineNo)) {
                printf("result: %d", eval(root));
            }
        }
        //printTokens();
        //reset tokens after each line
        tokens.count = 0;
        lineNo++;
    }

    report();

    fclose(file);
}