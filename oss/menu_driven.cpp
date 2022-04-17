#include <iostream>
using namespace std;

#define INSERT 1
#define DELETE 2
#define SHOW_FRONT 3
#define QUIT 4

class node
{
    public:
        string name;
        int score;
        void set__data(string s1, int s2);
};

void node::set__data(string s1, int s2)
{
    name = s1;
    score = s2;
}

class myqueue
{
    node a[10];
    node *front, *rear;
    public:
        myqueue();
        void insert_q(node t);
        node front_element();
        bool q_full();
        bool q_empty();
};


myqueue::myqueue()
{
    front = 0;
    rear = 0;
}

void myqueue::insert_q(node t)
{
    if(!q_full())
    {
        a[rear] = t;
        rear = (rear + 1) % 10;
    }
    else
        cout <<"q is full";
}


node myqueue::front_element()
{
    if(!q_empty())
    {
        return(*front);
    }
    else
    {
        cout << "error : queue empty\n\n";
    }
}

int get_a_cmd()
{
    int n;
    cout << "\n\n 1. insert a node \n";
    cout << " 2. delete a node \n";
    cout << " 3. Show the front element \n";
    cout << " 4. Quit \n";
    cout << " select a command : ";

    cin >> n;
    return n;
}

void myqueue::node_insert(myqueue &a)
{
    node tmp;
    string name;
    double score;

    cout << "name :";
    cin >> name;
    cout << "score :";
    cin >> score;
    tmp.set_data(name, score);
    a.insert_q(tmp);
}

void myqueue::node_delete(myqueue &a)
{
    node tmp;

    if(a.q_empty())
    {
        cout << "the queue is empty.\n";
        return;
    }

    tmp = a.delete_q();
    cout << "the node deleted :\n";
    cout << tmp.name << ":" << tmp.score << "\n";
}

void show_front(myqueue &a) //a도 가능 왜냐하면 내용 변경이 없기 때문에 상관 x
{
    node tmp;
    if(a.q_empty())
    {
        cout << "the queue is empty.\n";
        return;
    }
    tmp = a.front_element();
    cout << "the front element \n";
    cout << tmp.name << ":" << tmp.score << "\n";
}

int main()
{
    myqueue a;
    int cmd;
    do{
        cmd = get_a_cmd();
        switch (cmd)
        {
            case INSERT: node_insert(a);
                break;
            case DELETE: node_delete(a);
                break;
            case SHOW_FRONT: show_front(a);
                break;
            case QUIT:
                cout << "bye \n\n";
        }
    }
    while(cmd != QUIT);

    return 0;
}