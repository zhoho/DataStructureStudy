#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return(gcd(b, a%b));
}

int main()
{
    int a,b,res;
    cout << "input 2num";
    cin >> a >> b;

    res = gcd(a,b);

    cout << res;

    return 0;
}