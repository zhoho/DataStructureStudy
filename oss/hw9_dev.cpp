#include <iostream>
using namespace std;

class node
{
    public:
        string name;
        double score;
        node *link;
        void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class mylist
{
    node *head, *tail;
    public:
        mylist();
        void add_to_head(node t); 
        void add_to_tail(node t);
        node delete_from_head();
        int num_nodes();
        bool list_empty();
        double score_sum();
        double get_score(string t_name);
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
    if(tail == NULL) //만약에 tail null이면 tail도 첫 노드로
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

int mylist::num_nodes()
{
    node *t;
    int count = 0;
    for(t = head; t != NULL; t = t -> link)
        count ++;
    return count;
}

bool mylist::list_empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

double mylist::score_sum()
{
    node *t;
    double total = 0.0;
    for(t = head; t != NULL; t = t -> link)
        total += t -> score;
    return total;
}

double mylist::get_score(string t_name)
{
    bool res = false;
    node *t;
    for(t = head; t != NULL; t = t -> link)
    {
        if(t -> name == t_name)
        {
            res = true;
            break;
        }
    }
    if(res == false)
        return false;
    else
        return t -> score;
}

int mylist::remove_a_node(string t_name)
{
    bool res = false;
    node *t, *prev; // 전에꺼 가르키는 node생성
    prev = NULL;
    t = head;
    while((t != NULL) && (t -> name != t_name))
    {
        prev = t;
        t = t -> link;
        if(prev)
            prev -> link = t -> link;
        else
            head = t -> link;
        if(head == NULL)
            tail = prev;
    }
    delete t;
    if(t == NULL)
        return 0;
    else
        return 1;
}

int main()
{
    mylist a;
    node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; //1 check
    tmp.set_data("Park",91.3);
    a.add_to_tail(tmp);
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; //2 check 
    tmp = a.delete_from_head();
    cout << tmp.name << "is deleted\n"; //3 check
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";
    cout << "Park’s score : " << a.get_score("Park") << "\n"; //4 check 
    if(a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n"; //5 check 
    cout << a.num_nodes() << " : " << a.score_sum() << "\n"; // last check

    return 0;
}