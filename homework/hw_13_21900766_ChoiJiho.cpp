#include <iostream>
using namespace std;

#define APPEND 1
#define SHOWIN 2
#define SHOWPRE 3
#define SHOWPOST 4
#define SEARCH 5
#define QUIT 6


class bst_node
{
    public:
        string birth_day;
        string phone_number;
        string name;
        bst_node* left, *right;
        bst_node(); //빈공간 생성 constructor 
        bst_node(string n1, string s, string n2); // 초깃값 생성 constructor 
        void set_data(string n1, string s, string n2);
};

class bst_tree
{
    bst_node* root; //root를 가리키는 pointer bst node를 가르키는 pointer root를 유지하고 있다
    int csize; // 현재 노드수 
    public: 
        bst_tree(); //constructor 빈공간
        void insert_node(bst_node t); //node insert
        void show_inorder(); // 화면상에 출력
        void show_preorder();
        void show_postorder();
        bst_node search(string tid);
};

bst_node::bst_node()
{
    left = NULL;
    right = NULL;
}

bst_node::bst_node(string n1, string s, string n2)
{
    birth_day = n1;
    name = s;
    phone_number = n2;
}

void bst_node::set_data(string n1, string s, string n2)
{
    birth_day = n1;
    name = s;
    phone_number = n2;
}

bst_tree::bst_tree()
{
    csize = 0;
    root = NULL;
}

void inorder_print(bst_node *p)
{
    if(p==NULL) return;
    inorder_print(p->left);
    cout << p->birth_day << " : " << p->name << " : " << p->phone_number << "\n";
    inorder_print(p->right);
}

void bst_tree::show_inorder()
{   
    inorder_print(root);
}

// preorder 
void preorder_print(bst_node *p)
{
    if(p==NULL) return;
    cout << p->birth_day << " : " << p->name << " : " << p->phone_number << "\n";
    preorder_print(p->left);
    preorder_print(p->right);
}

void bst_tree::show_preorder()
{   
    preorder_print(root);
}
// postorder
void postorder_print(bst_node *p)
{
    if(p==NULL) return;
    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->birth_day << " : " << p->name << " : " << p->phone_number << "\n";
}

void bst_tree::show_postorder()
{   
    postorder_print(root);
}

bst_node bst_tree::search(string tid)
{
    bst_node *p;
    p = root;
    if(root == NULL)
    {
        bst_node tmp;
        tmp.set_data(0, "X", 0);
        cout << "The key" << tid << "does not exist\n";
        return tmp;
    }
    while(1)
    {
        if(p->birth_day == tid)
            return (*p);
        if(p->birth_day < tid)
        {
            if(p->right == NULL)
            {
                bst_node tmp;
                tmp.set_data(0, "X", 0);
                cout << "The key" << tid << "does not exist\n";
                return tmp;
            }
            else
                p = p->right;
        }
        else
        {
            if(p->left == NULL)
            {
                bst_node tmp;
                tmp.set_data(0, "X", 0);
                cout << "The key" << tid << "does not exist\n";
                return tmp;
            }
            else
                p = p->left;
        }
    }
}

void bst_tree::insert_node(bst_node t) // 주어진 어떤 key 값을 갖는 원소를 넣는 연산
{
    bst_node* p; // 두개의 pointer 
    bst_node* tmp;

    tmp = new bst_node; // 공간확보
    *tmp = t; // 값을 넣어라
    tmp->left = NULL;
    tmp->right = NULL;

    if(root == NULL)
    {
        root = tmp;
        return;
    }
    p = root;
    while(1)
    {
        if(p->birth_day == t.birth_day)
        {
            cout << "Insertion Failed : the Key" << t.birth_day << " already exists." << endl;
            return;
        }
        if(p->birth_day < t.birth_day)
        {
            if(p->right == NULL)
            {
                p->right = tmp;
                return;
            }
            else
                p = p->right;
        }
        else
        {
            if(p->left == NULL)
            {
                p->left = tmp;
                return;
            }
            else
                p = p->left;
        }
    }
}

int get_cmd()
{
    int n;
    cout << "-------------Hello! Pick Command-------------\n";
    cout << "---------------------------------------------\n";
    cout << "\n 1. Append new node\n";
    cout << " 2. Show inorder\n";
    cout << " 3. Show preorder\n";
    cout << " 4. Show postorder\n";
    cout << " 5. Search by birthday(ex 001027)\n";
    cout << " 6. Quit \n";
    cout << " Pick Commnad : ";

    cin >> n;
    return n;
}

void Append_node(bst_tree &t1)
{
    bst_node temp;
    string n1;
    string s;
    string n2;
    cout << "birthday : ";
    cin >> n1;
    cout << "name : ";
    cin >> s;
    cout << "phone number : ";
    cin >> n2;
    temp.set_data(n1,s,n2);
    t1.insert_node(temp);
}

void Search_key(bst_tree &t1)
{
    bst_node temp;
    string birth_key;
    cout << "put birth_day_key : ";
    cin >> birth_key;
    temp = t1.search(birth_key);
    cout << "\n -------" << birth_key << "'s record --------\n" << endl;
    cout << " birthday   : "<< temp.birth_day << endl;
    cout << " Name : "<< temp.name << endl;
    cout << " Phonenumber       : " << temp.phone_number << endl;
}

int main()
{
    bst_node temp;
    bst_tree t1;    
    int cmd;
    do
    {
        cmd = get_cmd();
        switch(cmd)
        {
            case APPEND: Append_node(t1);
                break;
            case SHOWIN: t1.show_inorder();
                break;
            case SHOWPRE: t1.show_preorder();
                break;
            case SHOWPOST: t1.show_postorder();
                break;
            case SEARCH: Search_key(t1);
                break;
            case QUIT: cout << "bye! \n\n";
        }
    }
    while(cmd != QUIT);
    return 0;
    }  