#include <stdio.h>
#include <string.h>


int str_search(int length, char* target, char* strings_arr[]);
int main (void)
{
    char* strings[] = {"hello", "sparta", "ilias", "test"};
    char* target;

    printf("enter search value: \n");
    fflush(stdin);
    scanf("%s", target);
    str_search(4, target, strings);

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