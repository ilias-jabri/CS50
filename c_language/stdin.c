#include <stdio.h>

int main() {
    char line[1000];
    fgets(line,1000, stdin);
    while(fgets(line, 1000, stdin) != NULL){
        
    }
    printf(line);

    return 0;
}