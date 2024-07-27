#include <stdio.h>
#include <string.h>


int str_search(int length, char* target, char* strings_arr[]);
int main (void)
{
    char* strings[] = {"hello", "sparta", "ilias", "test"};
    str_search(4, "ilias", strings);
}

int str_search(int length, char* target, char* strings_arr[])
{
    for(int i = 0; i<length; i++)
    {
        if(strcmp(strings_arr[i], target) == 0){
            printf("found");
            return 1;
        }
    }
    printf("not found.");
    return 0;
}