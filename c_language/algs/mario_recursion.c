#include <stdio.h>

int mario(int length);
int main(void)
{
    mario(6);
    return 0;
}
int mario(int length)
{
    if(length == 0) return 1;
    mario(length -1);
    {
        for(int i = 0; i<length; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}