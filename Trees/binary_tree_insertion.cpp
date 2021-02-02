#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Node (int val) {
    //     data = val;
    //     left = NULL;
    //     right = NULL;
    // }
};

Node* CreateNode(int val) {
    Node* newNode = new Node();
    if (!newNode) {
        cout<<"Memory error";
        return NULL;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        // root = new Node(data);       Can also be done like this, but we are making CreateNode function to check for Memory error also
        root = CreateNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }

    return NULL;
}

void inOrder(Node* temp) {
    if (temp == NULL)
        return;

    inOrder(temp->left);
    cout<<temp->data<<" ";
    inOrder(temp->right);
}

int main(){

    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout<<"Inoder traversal before insertion: ";
    inOrder(root);
    cout<<endl;

    insert(root, 16);

    cout<<"Inoder traversal after insertion: ";
    inOrder(root);
    cout<<endl;

    return 0;

}

