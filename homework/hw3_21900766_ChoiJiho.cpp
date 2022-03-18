#include <iostream>
using namespace std;

class mystack
{
    int stack[100];
    int top;
    public:
        void push(int a);
        int pop();
        bool stack_empty();
        void init();
};


void mystack::init()
{
    int top = 0;
}

void mystack::push(int a)
{
    stack[top] = a;
    top++;
}

int mystack::pop()
{
    top--;
    return(stack[top]);
}

bool mystack::stack_empty()
{
    if(top == 0) return true;
    else return false;
}

int main()
{
    mystack s1;
    int list[5] = { 32, 123, 27, 131, 242 }, i, x;
    s1.init();
    for (i = 0; i < 5; i++)
        if (list[i]> 100)
            s1.push( list[i]);
    while(!s1.stack_empty( ))
    {
        x = s1.pop( );
        cout << x << endl ; 
    }
    return 0;
}

