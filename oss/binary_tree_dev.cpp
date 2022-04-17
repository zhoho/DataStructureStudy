#include <iostream>
#include <string>

using namespace std;

class node
{
    public:
        string name;
        double score;
        node *left, *right;
        void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class mytree
{
    public:
        int node_count;
        node *root;
        mytree();
        int insert_root(node t);
        int insert_left(node *p, string tname, node tnode);
        int insert_right(node *p, string tname, node tnode);
        double score_sum();
        double score_average();
        void print_data_inorder();
        void print_data_preorder();
        void print_data_postorder();
};

mytree::mytree()
{
    node_count = 0;
    root = NULL;
}

int mytree::insert_root(node t)
{
    if(root != NULL)
        return 0;
    node *p;
    p = new node;
    (*p) = t;
    p -> left = NULL;
    p -> right = NULL;
    root = p;
    node_count ++;
    return 1;
}

int mytree::insert_left(node *p, string tname, node tnode)
{
    if(p == NULL)
        return 0;
    if(p -> name == tname)
    {
        if(p -> left != NULL)
            return -1;
    node *t;
    t = new node;
    (*t) = tnode;
    t -> left = NULL;
    t -> right = NULL;
    p -> left = t;
    return 1;
    }
    else
    {
        int result = insert_left(p -> left, tname, tnode);
        if(result != 0)
            return result;
        return insert_left(p -> right, tname, tnode);
    }
}

int mytree::insert_right(node *p, string tname, node tnode)
{
    if(p == NULL)
        return 0;
    if(p -> name == tname)
    {
        if(p -> right != NULL)
            return -1;
    node *t;
    t = new node;
    (*t) = tnode;
    t -> left = NULL;
    t -> right = NULL;
    p -> right = t;
    return 1;
    }
    else
    {
        int result = insert_right(p -> right, tname, tnode);
        if(result != 0)
            return result;
        return insert_right(p -> left, tname, tnode);
    }
}

double sum_allnodes(node *p)
{
    if(p == NULL)
        return 0;
    return
        sum_allnodes(p -> left) + sum_allnodes(p -> right) + p -> score;
}

double mytree::score_sum()
{
    return sum_allnodes(root);
}

// double mytree::score_average()
// {
//     double ave = sum_allnodes(root)/10;
//     return sum_allnodes(root);
// }

void inorder_print(node *p)
{
    if(p == NULL)
        return;
    inorder_print(p -> left);
    cout << p -> name << " : " << p -> score << "\n";
    inorder_print(p -> right);
}

void mytree::print_data_inorder()
{
    inorder_print(root);
}

void preorder_print(node *p)
{
    if(p == NULL)
        return;
    cout << p -> name << " : " << p -> score << "\n";
    preorder_print(p -> left);
    preorder_print(p -> right);
}

void mytree::print_data_preorder()
{
    preorder_print(root);
}

void postorder_print(node *p)
{
    if(p == NULL)
        return;
    postorder_print(p -> left);
    postorder_print(p -> right);
    cout << p -> name << " : " << p -> score << "\n";
}

void mytree::print_data_postorder()
{
    postorder_print(root);
}

int main()
{
    mytree thetree;
    node tmp;
    node *p;
    p = new node;
    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left(p -> left ,"Kim",tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right(p -> right,"Kim",tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left(p -> left,"Lee",tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right(p -> right,"Lee",tmp);
    tmp.set_data("cho", 7.7);
    thetree.insert_right(p -> right,"Park",tmp);

    cout << "Score Sum : " << thetree.score_sum() << "\n";
    //cout << "Score Average : " << thetree.score_average() << "\n";
    cout << "\n Inorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\n Preorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\n Postorder Traversal Result \n";
    thetree.print_data_postorder();

    return 0;
}