#include <stdio.h>

const int MAX_HEIGHT = 100;

void mario(void);
int main (void){


    mario();
    return 0;
}

void mario(void){
    int height;
    do{
        printf("enter the height - between 1 and 100: \n");
        scanf("%d", &height);
        if(height < 1 || height > MAX_HEIGHT){
            continue;
        }else break;
    }while(1);

    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= height - i; j++){
            printf(" ");
        }
        for(int k = 1; k <= i; k++){
            printf("#");
        }
        printf("  ");
        for(int k = 1; k <= i; k++){
            printf("#");
        }
        printf("\n");
    }
}