#include <iostream>
using namespace std;

int main()
{
    mystack  s1;
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;
    s1.init();
    for (i = 0; i < 5; i++)
        if (list[i]> 100)
            s1.push( list[i]);
    while(!s1.stack_empty( ))
    {
        x = s1.pop( );
        cout << x << endl ; 
    }
    
    return 0;
}