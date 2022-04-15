#include <iostream>
using namespace std;
typedef int *intArrayPtr;

int main()
{
    int d1, d2;
    cout << "Enter the row and column dimensions of the array: ";
    cin >> d1 >> d2;
    intArrayPtr *m = new intArrayPtr[d1];
    int i,j;
    for(i = 0; i < d1; i ++)
    {
        m[i] = new int[d2];
    }
    cout << "Enter " << d1 << "rows of " << d2 << "integers each: ";
    for(i = 0; i < d1; i++)
    {
        for(j = 0; j < d2; j++)
        {
            cin >> m[i][j];
        }
    }
    cout << "Echoing the 2 dimensional array: ";
    for(i = 0; i < d2; i++)
    {
        for(j = 0; j < d2; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for(i = 0; i < d1; i++)
        delete[] m[i];
    delete[] m;
    return 0;
}