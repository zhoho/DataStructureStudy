#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

class stack
{
    char s[SIZE];
    int top;
    public:
        stack();
        void push(char x);
        char pop();
        bool empty();
        bool full();
        char top_element();
};

stack::stack()
{
    top = 0;
}

void stack::push(char x)
{
    if(full())
        cout << "stack is full!";
    else
    {
        s[top] = x;
        top ++;
    }
}

char stack::pop()
{
    if(empty())
        return 0;
    else
    {
    top--;
    return s[top];
    }
}

bool stack::empty()
{
    if(top == 0)
        return 1;
    else
        return 0;
}

bool stack::full()
{
    if(top >= SIZE)
        return 1;
    else
        return 0;
}

char stack::top_element()
{
    if(empty())
        return 0;
    else
        return s[top - 1]; // top - 1 유의할것
}

int main(void)
{
    string input,output;
    stack stack;
    char a[SIZE];
    cout << "input : ";
    cin.getline(a,SIZE);
    input  = a;
    input.erase(remove(input.begin(), input.end(), ' '), input.end()); // 공백 지우기
    int len = input.size();
    int outputlen;
    bool k = false;
    
    for(int i = 0; i < len; i++)
    {
        stack.push(input[i]);
    }

    for(int i = 0; i < len/2; i++)
    {
        output += stack.pop();
    }

    if(len%2 == 1) // len이 홀수일때  ex)abcba
    {
        stack.pop();
    }

    outputlen = output.size();

    for(int i = outputlen - 1; i >= 0; i--)
    {
        if(stack.pop() == output[i])
            k = true;
        else
            k = false;
    }
    if(k == true)
        cout << "palindrome";
    else
        cout << "not palindrome";

    return 0;
}