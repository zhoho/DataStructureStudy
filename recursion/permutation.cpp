#include <iostream>
using namespace std;


int permutaion(int a, int b)
{
    if(b == 0)
        return 1;
    else
        return(a * permutaion(a - 1, b - 1));
}

int main()
{
    int a,b,res;
    cout << "insert 2 num";
    cin >> a >> b;

    res = permutaion(a,b);

    cout << res;
    return 0;
}