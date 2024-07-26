#include <stdio.h>


float avg(int size, float* marks);

int main(void){

    int nums_size = 10;
    float nums[] = {10, 10, 10, 10, 10, 15, 15, 15, 15, 20};

    float the_avg = avg(nums_size, nums);
    printf("the average mark is %.2f", the_avg);
    return 0;
}


float avg(int size, float* marks)
{

    printf("\n ========== ");
    printf("the last value in the array is: %.2f", *(marks + 9));
    printf("\n ========== \n");
    float sum = 0;
    for(int i = 0; i<size; i++){
        sum += marks[i];
    }
    return (float) sum / size;

}