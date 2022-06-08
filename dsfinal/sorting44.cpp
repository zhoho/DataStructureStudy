#include <cstdlib>
#include <iostream>
using namespace std;

int compare(const void *a, const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;

    if(*p1 == *p2)
        return 0;
    if(*p1 > *p2)
        return 1;
    if(*p1 < *p2)
        return -1;
}

int main()
{
    int list[10] = {25, 32 ,10 ,23, 44, 5, 69, 12, 99, 1};
    qsort(list, 10, sizeof(int), compare);

    for(int i = 0; i <10; i++)
        cout << list[i] << endl;
    
    return 0;
}