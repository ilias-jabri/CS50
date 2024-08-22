#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int size;
    int capacity;
} IntDArray;

IntDArray* expandIntDArr(IntDArray* Darr);
void printArray(int array[], int arrSize);

int main(void)
{
    IntDArray nums;
    nums.size = 10;
    nums.capacity = nums.size*1.3;
    nums.arr = malloc(nums.size * sizeof(int));
    if(nums.arr == NULL) {
        perror("failed memory allocation for an array at line 16");
        return 16;
    }
    
    for (int i = 0; i < nums.size; i++) nums.arr[i] = i+1;
    printArray(nums.arr, nums.capacity);

    // testing...
    expandIntDArr(&nums);
    printf("\n");
    printArray(nums.arr, nums.capacity);

}

IntDArray* expandIntDArr(IntDArray* Darr)
{
    int newCapacity = Darr->capacity * 1.3;
    int* newArr = calloc(newCapacity, sizeof(int));
    if(newArr == NULL) {
        perror("failed memory allocation for an array at line 16");
        exit(31);
    }

    for(int i = 0; i<Darr->size; i++){
        newArr[i] = Darr->arr[i];
    }

    free(Darr->arr);
    Darr->arr = newArr;
    Darr->capacity = newCapacity;

    return Darr;
}

IntDArray* shrinkIntDArr(IntDArray* Darr)
{
    if(!(Darr->capacity > Darr->size * 1.3)) return Darr;

    int shrinkedCapacity = Darr->size * 1.3;
    int* newArr = calloc(shrinkedCapacity, sizeof(int));
    if(newArr == NULL) {
        perror("failed memory allocation for an array at line 16");
        exit(31);
    }

    for(int i = 0; i<Darr->size; i++){
        newArr[i] = Darr->arr[i];
    }

    free(Darr->arr);
    Darr->arr = newArr;
    Darr->capacity = shrinkedCapacity;

    return Darr;
}

void printArray(int array[], int arrSize)
{
    printf("[");
    for(int i = 0; i < arrSize; i++)
    {
        if(i == 0) printf("%i", array[i]);
        else printf(",%i", array[i]);
    }
    printf("]");
}