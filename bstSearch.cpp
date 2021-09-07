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


node *bstSearchRecursive(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        bstSearchRecursive(root->left, key);
    }
    else
    {
        bstSearchRecursive(root->right, key);
    }
}

node *bstSearchIterative(node *root, int key)
{
    while (root != NULL)
    {

        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    node *root = new node(5);
    node *t1 = new node(3);
    node *t2 = new node(6);
    node *t3 = new node(4);
    node *t4 = new node(1);
    //          5
    //       /     \
    //     3         6
    //   /   \        
    // 1      4
    //
    //

    root->left = t1;
    root->right = t2;

    t1->left = t4;
    t1->right = t3;

    node *recData = bstSearchRecursive(root, 4);
    cout << "while searching recursively : \n";

    if (recData != NULL)
    {
        cout << "key found in address of : " << recData << "  and that data is :" << recData->data << endl;
    }
    else
    {
        cout << "Element not found !!";
    }

    node *iterData = bstSearchIterative(root, 3);
    cout << "while searching iteratively : \n";
    if (iterData != NULL)
    {
        cout << "key found in address of : " << iterData << "  and that data is :" << iterData->data << endl;
    }
    else
    {
        cout << "Element not found !!";
    }
   

    return 0;
}
