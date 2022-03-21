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

int main()
{
    int result = 0;
    string input;
    char t;
    mystack stack1;
    t = stack1.pop();
    //cin >> input;
    cout << "input some";
    char exp[SIZE];
    cin.getline(exp,SIZE);
    input = exp;
    int len = input.size();
    for(int i = 0; i < len; i++)
    { 
        if(result == 1)
            break;
        
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            for(int j = 0; j < len; j++)
            {
              if(match_check(i,j) == false) 
                  result = 1;
                  break;
            }
        }
    }
    if(result == 1)
        cout << "error";
    else
        cout << "good";

    return 0;
}