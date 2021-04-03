#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this-> data = data;
        left = right = NULL;
    }
};

void inOrder_using_morris_traversal(Node* root) {

    if (root==NULL) 
        return;

    Node* curr;
    Node* pre;
    curr = root;

    while(curr != NULL) {
        if (curr->left == NULL) {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else {

            pre = curr->left;
            while(pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr -> left;
            }

            else {
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }

        }
    }


}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    root->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    inOrder_using_morris_traversal(root);
}