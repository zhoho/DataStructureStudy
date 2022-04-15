#include <iostream>
using namespace std;
#define SIZE 100
// ( ),  { }, [ ]

class mystack
{
    int stack[SIZE];
    int top;
    public:
        void push(char a);
        char pop();
        bool stack_empty();
        void init();
};

void mystack::init()
{
    int top = 0;
}

void mystack::push(char a)
{
    stack[top] = a;
    top++;
}

char mystack::pop()
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
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
            stack1.push(input[i]);
        else if(input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
            if(stack1.stack_empty() == true)
                result = 1;
            else{
            t = stack1.pop();
            if(match_check(t,input[i]) == false)
                result = 1;
            }
        }
    }
    stack1.pop();
    if(stack1.stack_empty() == false) // 비어있지않으면 일치하지 않으므로 error
        result = 1;

    if(result == 0)
        cout << "good";
    else
        cout << "error";

    return 0;
}
