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

int main(void)
{
    string input, output;
    stack stack1;
    char a[SIZE];
    cout << "input some";
    cin.getline(a,SIZE);
    input = a;
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    int len = input.size();
    for(int i = 0; i < len; i++)
    {
        stack1.push(input[i]);
    }
    for(int i = 0; i < len/2; i++)
    {
        output += stack1.pop();
    }
    if(len%2==1)
    {
        stack1.pop();
    }
    int olen = output.size(); 
    bool k = true;
    for(int i = olen - 1; i > 0; i--)
    {
        if(stack1.pop() == output[i])
            k = true;
        else
            k = false;
    }
    if(k == true) cout << "palindrome";
    else cout << "not palindrome";
}
