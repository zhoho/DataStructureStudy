#include <iostream>
using namespace std;

int sum_even(int a)
{
    if(a % 2 == 1)
        a--;
    if(a <= 0)
        return 0;
    else
        return(a + sum_even(a - 2));
}

int main()
{
    int n;
    int total;
    cin >> n;
    total = sum_even(n);
    cout << total;
return 0;
}