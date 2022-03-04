#include <iostream>
#include <list>

void my_sort(int list[], int n)
{
    int j, k, min, t;
    for(j = 0; j < n; j++)
    {
        min = j;
        for(k = j + 1; k < n; k++)
        {
            if(list[k] < list[min])
            {
                min = k;
            }
        t = list[j];
        list[j] = list[min];
        list[min] = t;
        }
    }
}

int main()
{
int  list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
int  i;
      my_sort(list, 10);   // 배열 list의 원소 10개를 sort하는 함수
      for (i = 0; i< 10; i++)
             std::cout << list[i] << "\n" << std::endl;
      return 0;
}