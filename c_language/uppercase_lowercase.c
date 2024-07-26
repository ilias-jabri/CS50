#include <stdio.h>
#include <string.h>
#define UP_LOW_DIFF 32
#define true 1
#define false 0
typedef int bool;

char* lowercase(char sample[]);
char* uppercase(char sample[]);
bool str_compare(char* first, char* second);

int main(int argc, char* argv[])
{

    if(argc == 3){
        if(str_compare(argv[1], "lower"))
        {
            printf("%s", lowercase(argv[2]));
        }
        else if (str_compare(argv[1], "upper"))
        {
            printf("%s", uppercase(argv[2]));
        }
        else
        {
            printf("error: command must follow the following format\nup_low_case <lower|upper> \"text sample\"");
            return 1;
        }
    }else{
        printf("error: command must follow the following format\nup_low_case <lower|upper> \"text sample\"");
        return 1;
    }
}

char* lowercase(char sample[])
{
    for(int i = 0, length = strlen(sample); i < length; i++)
    {
        // using pointer arithmetic;
        if(*(sample + i) >= 'A' && *(sample + i) <= 'Z')
        {
            *(sample + i) = *(sample + i) + UP_LOW_DIFF;
        }
    }
    return sample;
}

char* uppercase(char sample[])
{
    for(int i = 0, length = strlen(sample); i < length; i++)
    {
        // using normal array indexing.
        if(sample[i] >= 'a' && sample[i] <= 'z')
        {
            sample[i] = sample[i] - UP_LOW_DIFF;
        }
    }
    return sample;
}

bool str_compare(char* first, char* second)
{
    int f_length = strlen(first);
    int s_length = strlen(second);
    if(f_length != s_length) return false;

    for(int i = 0; i<f_length; i++)
    {
        if(first[i] != second[i]) return false;
    }

    return true;
}