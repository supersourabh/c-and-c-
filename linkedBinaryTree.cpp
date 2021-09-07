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

int main()
{
    node *root = new node(10);
    node *t1 = new node(10);
    node *t2 = new node(20);
    node *t3 = new node(30);
    node *t4 = new node(40);
    node *t5 = new node(50);
    node *t6 = new node(60);

    root->left =t1;
    root->right =t2;

    t1->left =t3;
    t1->right =t4;

    t2->left =t5;
    t2->right =t6;
    
    return 0;
}
