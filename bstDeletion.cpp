#include <iostream>
#include <string.h>

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

node *inOrderPredecessor(node *root)
{
    root = root->left;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

node *deleteBST(node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteBST(root->right, value);
    }
    //deletion statargy
    else
    {
        // in order predecessor = ipo
        node *ipo = inOrderPredecessor(root);
        root->data = ipo->data;
        root->left = deleteBST(root->left, ipo->data);
    }

    return root;
}

int main()
{
    node *root = new node(5);
    node *t1 = new node(3);
    node *t2 = new node(10);
    node *t3 = new node(4);
    node *t4 = new node(1);
    //          5
    //       /     \
    //     3         10
    //   /   \      / \ 
    // 1      4    9   NULL
    //
    //

    root->left = t1;
    root->right = t2;

    t1->left = t4;
    t1->right = t3;

    inOrderTreeTraversal(root);

    deleteBST(root, 3);

    cout << "\n";

    inOrderTreeTraversal(root);

    return 0;
}