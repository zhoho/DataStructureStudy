#include <iostream>
using namespace std;
#define SIZE 100

class element
{
    public:
        string name;
        double score;
        void set_data(string n, double s);
};

void element::set_data(string n, double s)
{
    name = n;
    score = s;
}

class myheap
{
    element h[SIZE];
    int csize;
    public:
        myheap();
        int hsize();
        void insert_heap(element t);
        element delete_heap();
        bool heap_full();
        bool heap_empty();
        double score_sum();
        double score_average();
        int node_delete_by_name(string tname);
};

myheap::myheap()
{
    csize = 0;
}

int myheap::hsize()
{
    return csize;
}

void myheap::insert_heap(element t)
{
    int k;
    csize ++;
    k = csize;
    while((k != 1) && (t.score > h[k / 2].score))
    {
        h[k] = h[k / 2];
        k /= 2;
    }
    h[k] = t;
}

element myheap::delete_heap()
{
    element t;
    element tmp;
    int parent, child;

    t = h[1]; //root
    tmp = h[csize]; // save last node
    csize --;
    parent = 1;
    child = 2;
    while(child <= csize)
    {
        if((child < csize) && (h[child].score < h[child + 1].score))
            child ++;
        if(tmp.score >= h[child].score)
            break;
        h[parent] = h[child];
        parent = child;
        child *= 2;
    }
    h[parent] = tmp;
    return t;
}

double myheap::score_sum()
{
    return summation(h, 1, csize);   
}

double summation(element a[], int troot, int n)
{
    if(troot > n)
        return 0;
    return(a[troot].score + summation(a, 2*troot, n) + summation(a, 2*troot + 1, n));
}

double myheap::score_average()
{
    if(csize == 0)
        return 0;
    return score_sum()/csize;
}