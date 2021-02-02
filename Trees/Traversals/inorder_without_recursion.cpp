#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

// Iterative function for inorder tree
// Time Complexity of this method is O(n^2)
// Space Complexity will be O(h) where h is max. height of tree


void inOrder(Node* root){

    stack<Node*> s;
    Node* curr = root;

    while(curr != NULL || s.empty() == false)
    {
        // Reach left most node of current Node
        while(curr != NULL) {
            s.push(curr);
            curr = curr ->left;
        }

        // Setting current to stack top's element since current would be NULL due to last loop
        curr = s.top();
        s.pop();

        cout<<curr->data<<" ";

        // Now we need to traverse the tree's right subtree
        curr = curr ->right;

    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    return 0;
}