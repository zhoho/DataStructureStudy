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

    t = h[1];
    tmp = h[csize];
    csize --;
    parent = 1;
    child = 2;
    while(child <= csize)
    {
        if((child < csize) && (h[child].score < h[child + 1].score))
            child ++; // pick right child 
        if(tmp.score >= h[child].score)
            break;
        h[parent] = h[child];
        parent = child;
        child *= 2;
    }
    h[parent] = tmp;
    return t;
}

bool myheap::heap_full()
{
    return (csize >= SIZE-1);
}

bool myheap::heap_empty()
{
    return (csize == 0);
}

int main()
{
   myheap h1;
   element temp;
   temp.set_data("Kim", 88);
   h1.insert_heap(temp);
   temp.set_data("Lee", 77);
   h1.insert_heap(temp);
   temp.set_data("Park", 98);
   h1.insert_heap(temp);
   temp.set_data("Choi", 74);
   h1.insert_heap(temp);
   temp.set_data("Ryu", 94);
   h1.insert_heap(temp);
   temp.set_data("Cho", 85);
   h1.insert_heap(temp);
   while (h1.hsize() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
   }
   return 0;
}