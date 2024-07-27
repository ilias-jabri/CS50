// Online C compiler to run C program online
#include <stdio.h>
int binary_search(int arr_size, int nums[], int needle);

int main() {
    // Write C code here
    int arr_size = 10;
    int nums[] = {1,2,3,4,5,6,7,8,99,102};
    
    binary_search(arr_size, nums, 7);

    return 0;
}
int binary_search(int arr_size, int nums[], int needle)
{
    int start = 0;
    int end = arr_size - 1;
    int middle = arr_size / 2;
    int i = 0;
    while(start <= end){
        middle = start + (end - start) / 2;
        if(nums[middle] == needle){
            printf("found");
            return 1;
        }else if(nums[middle] > needle){
            end = middle - 1;
        }else if(nums[middle] < needle){
            start = middle + 1;
        } i++;
        printf("start %i, middle %i, end %i\n", start, middle, end);
    }
    printf("not found");
    return 0;
}