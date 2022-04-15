#include <iostream>
using namespace std;
#define SIZE 100

class mystack
{
    int stack[SIZE];
    int top;
    public:
        void push(int n);
        int pop();
        bool stack_empty();
        bool stack_full();
        void init();
};

void mystack::init()
{
    int top = 0;
}


void mystack::push(int n)
{
    if(stack_full())
        cout << "stack is full";
    else
    {
        stack[top] = n;
        top ++;
    }
}

int mystack::pop()
{
    if(stack_empty())
        return 0;
    else
    {
        top --;
        return stack[top];
    }
}

bool mystack::stack_empty()
{
    if(top == 0)
        return 1;
    else
        return 0;
}

bool mystack::stack_full()
{
    if(top >= SIZE)
        return 1;
    else
        return 0;
}


int main()
{
mystack  s1;

int list[5] = { 32, 123, 27, 131, 242 }, i, x;
  s1.init();
  for (i = 0; i < 5; i++ )
    if (list[i]> 100)
        s1.push( list[i] );
  while (!s1.stack_empty())
  {
    x = s1.pop( );
    cout << x << endl ; 
  }
  return 0;
}