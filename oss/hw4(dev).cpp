#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;

//infix to postfix

class mystack
{
    char s[SIZE];
    int top;
    public:
        mystack();
        void push(char x);
        char pop();
        bool stack_empty();
        bool stack_full();
        char top_element();
};

mystack::mystack()
{
    top = 0;
}

void mystack::push(char x)
{
    if(stack_full())
        cout << "stack is full!";
    else
        s[top] = x;
        top ++;
}

char mystack::pop()
{
    if(stack_empty())
        return 0;
    else
    {
        top --;
        return s[top];
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

char mystack::top_element()
{
    if(stack_empty())
        return 0;
    else
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
    mystack stack;
    string input, output;
    cout << "input infix";
    cin >> input;
    stack.push(EOS);
    
    for(int i = 0; i < input.size(); i++)
    {
        if(is_operand(input[i] == true))
            output += input[i];
        else
        {
        if(input[i] == '(')
        {
            stack.push(input[i]);
        }
        else if(input[i] == ')')
        {
            while(1)
            {
                if(stack.top_element() == '(')
                    break;
                else
                output += stack.pop();
            }
            stack.pop();
        }
        else
        {
            if(get_precedence(stack.top_element() < get_precedence(input[i])))
            {
                while(1)
                {
                    output += stack.pop();
                    if(get_precedence(stack.top_element() < get_precedence(input[i])))
                        break;
                }
                stack.push(input[i]);
            }
            else
                stack.push(input[i]);
        }
        }
    }
// Infix expression을 Postfix expression으로 변환하는 프로그램을 작성하시오.
// Test Case 예)
// 입력 :  a * (b + c)
// 출력 :  a b c + *
    while(stack.top_element() != '$')
        output += stack.pop();

    cout << output;

    return 0;
}