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

void inOrderTreeTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTreeTraversal(root->left);
        cout << root->data << " ";
        inOrderTreeTraversal(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    node *root = new node(5);
    node *t1 = new node(3);
    node *t2 = new node(2);
    node *t3 = new node(6);
    node *t4 = new node(5);
    node *t5 = new node(4);
    node *t6 = new node(7);
    node *t7 = new node(8);
    node *t8 = new node(1);
    node *t9 = new node(3);
    //          5
    //       /     \
    //     3         6
    //   /   \        
    // 1      4
    //
    //

    root->left = t1;
    root->right = t3;

    t1->left = t8;
    t1->right = t5;

    // t2->left = t9;
    // t2->right = t7;

    // t5->left = t4;
    // t5->right = t6;

    inOrderTreeTraversal(root);
    cout << "\n" << isBST(root);

    return 0;
}