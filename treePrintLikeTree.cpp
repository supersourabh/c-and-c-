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

void printingLikeTree(node *root , int level =0)
{
    if(root == NULL) return;
    cout<< root->data << " \n";
    printingLikeTree(root->right , level+1);
    for (int i = 0; i < level; i++)
    {
        cout<<" ";
    }
    printingLikeTree(root->left , level+1);
    
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

    printingLikeTree(root);

    return 0;
}