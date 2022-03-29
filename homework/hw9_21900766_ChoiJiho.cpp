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

void node::set_data(string s,double n)
{
    name = s;
    score = n;
}

class my_list
{
    node *head, *tail;
    public:
        my_list();
        void add_to_head(node t);
        void add_to_tail(node t);
        node delete_from_head();
        int num_nodes();
        bool list_empty();
        double score_sum();
        double get_score(string t_name);
        int remove_a_node(string t_name);
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p -> link = head;
    head = p;
    if(tail == NULL)
        tail = p;
}

void my_list::add_to_tail(node t)
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

node my_list::delete_from_head()
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

int my_list::num_nodes()
{
    node *t;
    int count = 0;
    for(t = head; t != NULL; t = t -> link)
        count ++;
    return count;
}

bool my_list::list_empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

double my_list::score_sum()
{
    node *t;
    double total = 0.0;
    for(t = head; t != NULL; t = t -> link)
        total +=  t -> score;
    return total;
}

double my_list::get_score(string t_name)
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
        if(res == false) return false;
        else
            return t -> score;
}

int my_list::remove_a_node(string t_name)
{  
    bool res = false;
    node *t, *prev;
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
    my_list a;
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