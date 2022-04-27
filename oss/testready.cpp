#include <iostream>
using namespace std;
#define SIZE 100

// class mystack
// {
//     int stack[SIZE];
//     int top;
//     public:
//         void push(int n);
//         int pop();
//         bool stack_empty();
//         bool stack_full();
//         void init();
// };

// void mystack::init()
// {
//     int top = 0;
// }

// void mystack::push(int n)
// {
//     if(stack_full())
//         cout << "stack is full";
//     else
//     {
//         stack[top] = n;
//         top ++;
//     }
// }

// int mystack::pop()
// {
//     if(stack_empty())
//         return 0;
//     else
//     {
//         top --;
//         return stack[top];
//     }
// }

// bool mystack::stack_empty()
// {
//     if(top == 0)
//         return 1;
//     else
//         return 0;
// }

// bool mystack::stack_full()
// {
//     if(top >= SIZE)
//         return 1;
//     else
//         return 0;
// }





// class element
// {
//     public:
//         string title;
//         int pages;
//         int price;
//         void set_data(string s1, int s2, int s3);
// };

// void element::set_data(string s1, int s2, int s3)
// {
//     title = s1;
//     pages = s2;
//     price = s3;
// }

// class myqueue
// {
//     element q[SIZE];
//     int front, rear;
//     public:
//         myqueue();
//         void insert_q(element x);
//         element delete_q();
//         bool queue_full();
//         bool queue_empty();
// };

// myqueue::myqueue()
// {
//     front = 0;
//     rear = 0;
// }

// void myqueue::insert_q(element x)
// {
//     if(!queue_full())
//     {
//         q[rear] = x;
//         rear = (rear + 1) % SIZE;
//     }
//     else
//         cout << "queue is full!";
// }

// element myqueue::delete_q()
// {
//     element tmp;
//     if(!queue_empty())
//     {
//         tmp = q[front];
//         front = (front + 1) % SIZE;
//         return tmp;
//     }
// }

// //////important thing

// bool myqueue::queue_empty()
// {
//     if(rear == front)
//         return 1;
//     else
//         return 0;
// }

// bool myqueue::queue_full()
// {
//     if((rear + 1) % SIZE == front)
//         return 1;
//     else
//         return 0;
// }

class node
{
    public:
        string name;
        double score;
        node *link;
        void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class mylist
{
    node *head, *tail;
    public:
        mylist();
        void add_to_head(node t);
        void add_to_tail(node t);
        node delete_from_head();
        int num_nodes();
        bool list_empty();
        double score_sum();
        double get_score(string t_name);
        int remove_a_node(string t_name);
};

mylist::mylist()
{
    head = NULL;
    tail = NULL;
}

void mylist::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p -> link = head;
    head = p;
    if(tail == NULL)
        tail = p;
}

void mylist::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p -> link = NULL;
    if(tail != NULL)
        tail -> link = p;
    else
        head = p;
    tail = p;
}