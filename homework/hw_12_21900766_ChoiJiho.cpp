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

double myheap::score_sum()
{
    return summation(h, 1, csize);
}

double summation(element a[], int troot, int n)
{
    if(troot > n)
        return 0;
    return (a[troot].score + summation(a, 2*troot, n) + summation(a, 2*troot + 1, n));
}

double myheap::score_average()
{
    if(csize == 0)
        return 0;
    return score_sum() / csize;
}

int myheap::node_delete_by_name(string tname)
{
    if(csize == 0)
        return 0;
    if(delete_node(h, 1, tname, csize) == 1)
    {
        csize --;
        return 1;
    }
    else
        return 0;
}

int delete_node(element a[], int troot, string tname, int n)
{
    if (troot > n)
        return 0;
    if (a[troot] == tname)
        return 1;
    else
        
}

void heap_adjust(element a[], int troot, int size)
{
    
}


int main()

{
   element a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}};
   myheap h1(a, 6);
   cout << "Number of nodes : " << h1.hsize() << endl;
   cout << "Score Sum = " << h1.score_sum() << endl;
   cout << "Score average = " << h1.score_average() << endl;
   h1.node_delete_by_name("Kim");
   cout << "\n-- After the deletion operation. --\n\n";
   cout << "Number of nodes : " << h1.hsize() << endl;
   cout << "Score Sum = " << h1.score_sum() << endl;
   cout << "Score average = " << h1.score_average() << endl;
   while (h1.hsize() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
   }
   return 0;
}