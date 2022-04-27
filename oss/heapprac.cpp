#include <iostream>
#define SIZE 100

using namespace std;

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

bool myheap::heap_empty()
{
    return (csize == 0);
}

bool myheap::heap_full()
{
    return (csize >= SIZE -1);
}

int myheap::hsize()
{
    return csize;
}

int main()
{
    myheap h1;

    element tmp;
    tmp.set_data("Kim", 88);
    h1.insert_heap(tmp);
    tmp.set_data("Lee", 22);
    h1.insert_heap(tmp);
    tmp.set_data("ho", 100);
    h1.insert_heap(tmp);
    tmp.set_data("zho", 99);
    h1.insert_heap(tmp);
    tmp.set_data("choi", 98);
    h1.insert_heap(tmp);
    tmp.set_data("park", 55);
    h1.insert_heap(tmp);

    while(h1.hsize() > 0)
    {
        tmp = h1.delete_heap();
        cout << tmp.name << ":" << tmp.score << "\n";
    }
    return 0;
}