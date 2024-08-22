#include <stdio.h>

void selectionSort(int nums[], int arrSize);
void bubbleSort(int nums[], int arrSize);
void printArray(int array[], int arrSize);
int main (void)
{
    
    int nums[] = {1,4999,2,77,45,77,80348, 3425};
    bubbleSort(nums, 8);
    printArray(nums, 8);
    
    return 0;
}

void bubbleSort(int arr[], int arrSize)
{
    int swaps = 1;
    int sorted = 0;
    while(swaps > 0){
        swaps = 0;
        for(int i = 1; i < arrSize - sorted; i++){
            if(arr[i - 1] > arr[i]){
                int tempRef = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = tempRef;
                swaps++;
            }
        }
        sorted++;
    }
}

void selectionSort(int nums[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < arrSize; j++) 
        {
            if(nums[i] > nums[j]) minIdx = j;
        }
        int tempRef = nums[minIdx];
        nums[minIdx] = nums[i];
        nums[i] = tempRef;
    }
}

void printArray(int array[], int arrSize)
{
    printf("[");
    for(int i = 0; i < arrSize; i++)
    {
        if(i == arrSize-1){
            printf("%i"); continue;
        }
        printf("%i,", array[i]);
    }
    printf("]");
}