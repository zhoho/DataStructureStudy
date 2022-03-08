#include <stdio.h>

int sumArray(int* array, int n);

int main(void)
{
    int intArray[3];
    for(int i = 0; i < 3; i++)
    {
        printf("num?");
        scanf("%d",&intArray[i]);
    }

    // int sum = sumArray(intArray, 3);
    
    // for(int i = 0; i < 3; i++)
    // {
    //     printf("%d",intArray[i]);
    // }

    printf("%d",sumArray(intArray, 3));

    return 0;
}

int sumArray(int* array, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}