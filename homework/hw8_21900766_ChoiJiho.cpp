#include <iostream>
using namespace std;

int find_max(int* a, int b)
{
    int m;
    if (b == 0)
        return a[0];
        
    m = find_max(a, b - 1);

    if(m > a[b])
        return m;
    else
        return a[b];
}

int main()
{
int  a[10] = { 24, 12, 33, 27, 41, 15, 84, 52, 16, 72 };
int  m;
m = find_max(a, 10);
cout << m;

return 0;
}