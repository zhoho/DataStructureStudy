#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;

//infix to postfix

class stack
{
    char s[SIZE];
    int top;
    public:
        stack();
        void push(char x);
        char pop();
        bool empty();
        char top_element();
};

stack::stack()
{
    top = 0;
}

void stack::push(char x)
{
    s[top] = x;
    top++;
}

char stack::pop()
{
    top--;
    return s[top];
}

bool stack::empty()
{
    return(top == 0);
}

char stack::top_element()
{
    return s[top - 1];
}

bool is_operand(char ch){
    if((ch == '(') || (ch == ')') || (ch == '+') || (ch == '-') ||(ch == '*') || (ch == '/') ||(ch == '%') ||(ch == '$'))
        return false;
    else
        return true;
}

int get_precedence(char a)
{
    if ((a =='$') || (a == '(' )) 
        return 0;
    else if ((a =='+') || (a == '-' )) 
        return 1;
    else if ((a =='*') || (a == '/' ) || (a == '%')) 
        return 2;
    else return 3;
}

int main(void)
{
    stack stack1;
    string input, output;
    cout << "input infix";
    cin >> input;
    // input += EOS;
    stack1.push(EOS);

    for(int i = 0; i < input.size(); i++)
    {
        if(is_operand(input[i]) == true)
            output += input[i];
        else
            if(input[i] == '(')
            {
                stack1.push(input[i]);
            }
            else if(input[i] == ')')
            {
                while(stack1.top_element() != '(')
                {
                    output += stack1.top_element();
                    stack1.pop();
                }
                stack1.pop();
            }
            else
            {
                
            }


            
    }
    while(stack1.top_element() == '$')
    {
        output += stack1.pop();
    }
    cout << output;

    return 0;
}