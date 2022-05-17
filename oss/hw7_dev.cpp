#include <iostream>
using namespace std;
#define SIZE 10

class element
{
    public:
        string title;
        int pages;
        int price;
        void set_data(string s1, int s2, int s3);
};

void element::set_data(string s1, int s2, int s3)
{
    title = s1;
    pages = s2;
    price = s3;
}

class myqueue
{
    element q[SIZE];
    int front, rear;
    public:
        myqueue();
        void insert_q(element x);
        element delete_q();
        bool queue_full();
        bool queue_empty();
};

myqueue::myqueue()
{
    front = 0;
    rear = 0;
}

void myqueue::insert_q(element x)
{
    if(!queue_full())
    {
        q[rear] = x;
        rear = (rear + 1) % SIZE;
    }
    else
        cout << "queue is full!";
}

element myqueue::delete_q()
{
    element tmp;
    element a;
    if(!queue_empty())
    {
        tmp = q[front];
        front = (front + 1) % SIZE;
        return tmp;
    }
}

bool myqueue::queue_empty()
{
    if(rear == front)
        return true;
    else
        return false;
}

bool myqueue::queue_full()
{
    if((rear + 1)%SIZE == front)
        return true;
    else
        return false;
}

int main()
{
    myqueue a;
    element tmp;
    
    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while(!a.queue_empty())
    {
        tmp = a.delete_q();
        cout << tmp.title << " : " << tmp.pages << " : " << tmp.price << "\n";
    }

    return 0;
}