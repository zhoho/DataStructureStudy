#include <cstdlib>
#include <iostream>
using namespace std;

int compare_sid(const void *a, const void *b)
{
    s_record *p1 = (s_record *)a;
    s_record *p2 = (s_record *)b;

    if(p1 -> s_id < p2 -> s_id)
        return -1;
    if(p1 -> s_id == p2 -> s_id)
        return 0;
    if(p1 -> s_id > p2 -> s_id)
        return 1;
    
}

int main(){
    
    qsort(list, 12, sizeof(s_record), compare_sid);
    show_thelist(s_list,n);

    return 0;
}