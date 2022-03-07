#include <iostream>

using namespace std;

int s;
int list[100001];

void push(int x){
    list[s] = x;
    s ++;
}

int pop(){
    if(s == 0) return -1;
    int k = list[s - 1];
    s --;
    return k;
}

int top(){
    if(s == 0) return -1;
    return list[s - 1];
}

int size(){
    return s;
}

int empty(){
    if(s == 0) return 1;
    else return 0;
}


int main(){
int n;
    std::cin >> n;

    while (n--){
        string str;
        std::cin >> str;

        if (str == "push"){
            int n;
            std::cin >> n;
            push(n);
        }
        if (str == "pop") std::cout << pop() << '\n';
        if (str == "top") std::cout << top() << '\n';
        if (str == "size") std::cout << size() << '\n';
        if (str == "empty") std::cout << empty() << '\n';
    }

}