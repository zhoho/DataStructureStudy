#include <iostream>
using namespace std;
#define SIZE 100
// ( ),  { }, [ ]

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

bool match_check(int c1, int c2)
{
    if((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') ||(c1 == '{' && c2 == '}')) 
        return true;
    else
        return false;
}

int main(void)
{
    int result = 0;
    char t;
    string input;
    mystack stack1;
    char exp[SIZE];
    cout << "input some : ";
    cin.getline(exp,SIZE);
    input = exp;
    int len = input.size();
    for(int i = 0; i < len; i++)
    {
        stack1.push(input[i]);
    }
    for(int i = 0; i < len; i++)
    {
        t = stack1.pop();
        if(match_check(t,input[i]) == true)
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    if(result == 0)
        cout << "good";
    else
        cout << "error";

    return 0;
}