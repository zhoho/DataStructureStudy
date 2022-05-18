#include <iostream>
using namespace std;

class bst_node
{
    public:
        string s_id;
        string name;
        double score;
        bst_node *left, *right;
        bst_node();
        //bst_node(string s1, string s2, double n);
        void set_data(string s1, string s2, double n);
};

class bst_tree
{
    bst_node* root;
    int csize;
    public:
        bst_tree();
        void insert_node(bst_node t);
        void show_inorder();
        bst_node search(string tid);
};

bst_node::bst_node()
{
    left = NULL;
    right = NULL;
}

void bst_node::set_data(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

//여기부터 tree구현
bst_tree::bst_tree()
{
    csize = 0;
    root = NULL;
}

void inorder_print(bst_node *p)
{
    if(p==NULL)
        return;
    inorder_print(p->left);
    cout << p->s_id << " : " << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void bst_tree::show_inorder()
{
    inorder_print(root);
}