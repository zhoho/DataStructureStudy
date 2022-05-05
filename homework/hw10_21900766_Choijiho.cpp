#include <iostream>
using namespace std;

class node
{
    public:
        string s_title;
        int npages;
        int price;;
        node *link;
        void set_data(string s, int s1, int s2);
};

void node::set_data(string s, int s1, int s2)
{
    s_title = s;
    npages = s1;
    price = s2;
}

class mylist
{
    node *head, *tail;
    public:
        mylist();
        void add_to_head(node t); 
        void add_to_tail(node t);
        node delete_from_head();
        bool list_empty();
        int remove_a_node(string t_name);
};

mylist::mylist()
{
    head = NULL;
    tail = NULL;
}

void mylist::add_to_head(node t)
{
    node *p;
    p = new node; // dynamic memory로 부터 node공간 확보
    (*p) = t; // node에 데이터값 저장
    p -> link = head; // p의 링크가 헤드를 가르키도록
    head = p;         // head가 p를 가르키도록
    if(tail == NULL) //만약에 tail null이면 tail도 첫 노드
        tail = p;
}

void mylist::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p -> link = NULL;
    if(tail != NULL)
        tail -> link = p;
    else
        head = p;
    tail = p;
}

node mylist::delete_from_head()
{
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head -> link;
    delete t;
    if(head == NULL)
        tail = NULL;
    return temp;
}

bool mylist::list_empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

int main()
{
    mylist a;
    node tmp;
    
    tmp.set_data("C++ Programming", 534, 35000);
    a.add_to_tail(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.add_to_tail(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.add_to_tail(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.add_to_tail(tmp);
    
    while (!a.list_empty())
    {
        tmp = a.delete_from_head();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }
}