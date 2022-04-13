#include <iostream>
using namespace std;

int arr_sum(int *a ,int n)
{
    if(n == 0)
        return 0;
    else
        return(a[n - 1] + arr_sum(a, n -1));
}

int main()
{
    int a[10] = {1,4,5,6,2,4,2,6,8,9};
    int n;
    int res;
    cin >> n;

    res = arr_sum(a,n);

    cout << res;
    
    return 0;
}