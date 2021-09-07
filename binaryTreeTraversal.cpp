#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int data)
    {
        this->data = data;
    }
};

void preOrderTreeTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrderTreeTraversal(root->left);
        preOrderTreeTraversal(root->right);
    }
}

void postOrderTreeTraversal(node *root)
{
    if (root != NULL)
    {
        postOrderTreeTraversal(root->left);
        postOrderTreeTraversal(root->right);
        cout << root->data << " ";
    }
}

void inOrderTreeTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTreeTraversal(root->left);
        cout << root->data << " ";
        inOrderTreeTraversal(root->right);
    }
}

int main()
{
    node *root = new node(10);
    node *t1 = new node(20);
    node *t2 = new node(30);
    node *t3 = new node(40);
    node *t4 = new node(50);
    node *t5 = new node(60);
    node *t6 = new node(70);

    root->left = t1;
    root->right = t2;

    t1->left = t3;
    t1->right = t4;

    t2->left = t5;
    t2->right = t6;

    preOrderTreeTraversal(root);
    cout<<"\n";
    postOrderTreeTraversal(root);
    cout<<"\n";
    inOrderTreeTraversal(root);

    return 0;
}
