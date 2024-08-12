// Online C compiler to run C program online
#include <stdio.h>

int strcmp(char* first, char* second);
int main() {
    // Write C code here
    char* sample = "hello worlddd";
    printf("%i", strcmp(sample, "hello worlddd"));
    char a = 'a';
    char A = 'a';
    printf("diff is %i", a - A);

    return 0;
}
int strcmp(char* first, char* second)
{
    int areEqual = 1;
    for(int i = 0; i < 99999; i++)
    {
        if(first[i] == '\0' && second[i] == '\0') break;
        if((first[i] == '\0') != (second[i] == '\0'))
        {
            areEqual = 0; break;
        }
        if(first[i] != second[i]) 
        {
            areEqual = 0; break;
        }
    }
    return areEqual;
}