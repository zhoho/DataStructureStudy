#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int list[10] = {1,3,5,11,42,2,40,112,0,40};
    sort(list, list + 10);
    for(int i = 0; i < 10; i++)
        cout << list[i] << '\n';
    cout << list;
}