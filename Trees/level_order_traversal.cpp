#include <iostream>
#include<queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    else
    {
        int l_height = height(root->left);
        int r_height = height(root->right);

        if (l_height > r_height)
            return l_height + 1;
        else
        {
            return r_height + 1;
        }
    }
}

void printGivenLevel(Node *root, int level) {

    if (root== NULL)
        return;
    
    if(level == 1)
        cout<<root->data<<" ";
    
    else {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(Node *root)
{

    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

void printLevelOrder_using_queue(Node* root) {

    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        
        if(temp->right)
            q.push(temp->right);

    }
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Now next is BFS using 2 function Algo"<<endl;
    printLevelOrder(root);

    cout<<endl;
    cout<<"Now next is BFS using queues"<<endl;

    printLevelOrder_using_queue(root);

    return 0;
}