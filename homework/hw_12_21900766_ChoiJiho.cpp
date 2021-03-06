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
    int csize; // the number of elements
    public:
        myheap();
        myheap(element a[], int n);
        int hsize();
        void insert_heap(element t);
        element delete_heap();
        bool heap_full();
        bool heap_empty();
        double score_sum();
        double score_average();
        int node_delete_by_name(string tname);
        void adjust(int troot);
};

myheap::myheap(element a[], int n)
{
    int k;

    for(k = 1; k <= n; k++)
        h[k] = a[k-1];
    csize = n;

    for(k = n/2; k >= 1; k--)
        adjust(k);
}

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
    k = csize; // 끝원소 위치
    while((k != 1) && (t.score > h[k / 2].score)) // k != root 도달
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
    int parent, child; //array에 저장 

    t = h[1]; //root
    tmp = h[csize]; // 끝원소 저장
    csize --;
    parent = 1; //root
    child = 2; // root의 left child
    while(child <= csize) //child가 존재
    {
        if((child < csize) && (h[child].score < h[child + 1].score)) // 오른쪽이 있고 오른쪽이 크면
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
    if (a[troot].name == tname)
        a[troot] = a[n];
        heap_adjust()
        return 1;
    else

}

void myheap::adjust(int troot)
{
    double tmpkey;
    int child;
    element tmp;

    tmp = h[troot];
    tmpkey = h[troot].score;
    child = 2 * troot;

    while(child <= csize)
    {
        if((child < csize) && (h[child].score) < (h[child + 1].score))
            child ++;
        if(tmpkey > h[child].score)
            break;
        else
        {
            h[child/2] = h[child];
            child *= 2;
        }
    }
    h[child/2] = tmp;
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