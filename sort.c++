#include <iostream> 
#include <list> 

void selection_sort(int list[], int n)
{
    int i,j,min,t;
    for (i = 0; j < n; i++)
    {
        min = i;
        for ( j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        t = list[i];
        list[i] = list[min];
        list[min] = t; 
        }
    }
}
