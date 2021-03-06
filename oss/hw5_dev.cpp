#include <iostream>
using namespace std;
#define SIZE 100

class mystack
{
    int stack[SIZE];
    int top;
    public:
        void push(char a);
        char pop();
        bool stack_empty();
        bool stack_full();
        mystack();
};

mystack::mystack()
{
    int top = 0;
}

void mystack::push(char a)
{
    if(stack_full())
        cout << "stack is full!";
    else
    {
    stack[top] = a;
    top++;
    }
}

char mystack::pop()
{
    if(stack_empty())
        return 0;
    else
    {
    top--;
    return(stack[top]);
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

bool match_check(int c1, int c2)
{
    if((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') ||(c1 == '{' && c2 == '}')) 
        return true;
    else
        return false;
}

int main()
{
    int result = 0;
    char t;
    string input;
    mystack stack;
    char exp[SIZE];
    cout << "input : ";
    cin.getline(exp,SIZE);
    input = exp;
    char errorcheck[10];
    int len = input.size();

    for(int i = 0; i < len; i++)
    {
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
            stack.push(input[i]);
        else if(input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
            if(stack.stack_empty())
            {
                result = 1;
            }
            else
            {
                t = stack.pop();
                if(!match_check(t, input[i]))
                {
                    result = 2;
                    errorcheck[0] = t, errorcheck[1] = input[i];
                }
            }
        }
    }
    stack.pop();
    if(!stack.stack_empty())
        result = 1;
    if(result == 0)
        cout << "이상없음";
    else if(result == 1)
        cout << "닫는 괄호 누락";
    else
        cout << "괄호 불일치" << errorcheck[0] << errorcheck[1];

    return 0;
}