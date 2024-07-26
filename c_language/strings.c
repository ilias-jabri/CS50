#include <stdio.h>
#include <string.h>

int main (void)
{
    char* fruits[3]; 
    fruits[0] = "banan";
    fruits[1] = "apple";
    fruits[2] = "orange";
    
    printf("length of %s is %i", fruits[0], strlen(fruits[0]));
    
    return 0;
}
