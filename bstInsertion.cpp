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



int insertBST(node *root, int data)
{
    node *prev = NULL;
    
    try
    {
        //searching for position to insert
        while (root != NULL)
        {
            prev = root;
            if (data == root->data)
            {
                throw "Error: duplicate value in tree " ;
            }
            else if (data < root->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        //creating new node
        node *newNode = new node(data);

        //cheking data intigrity
        if (data < prev->data)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
    }
    catch (const char *msg)
    {
        cerr << msg << '\n';
    }
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
    cout << "\n";
    insertBST(root, 9);
    inOrderTreeTraversal(root);
    cout << "\n";
    insertBST(root, 6);
    inOrderTreeTraversal(root);

    return 0;
}