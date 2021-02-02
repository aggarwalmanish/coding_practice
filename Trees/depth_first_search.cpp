#include<iostream>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void print_Inorder(Node* root) {

    if(root==NULL)
        return;

    print_Inorder(root->left);
    cout<<root->data<<" ";
    print_Inorder(root->right);
}

void print_Preorder(Node* root) {

    if(root==NULL)
        return;

    cout<<root->data<<" ";
    print_Preorder(root->left);
    print_Preorder(root->right);
}

void print_Postorder(Node* root) {

    if(root==NULL)
        return;

    print_Postorder(root->left);
    print_Postorder(root->right);
    cout<<root->data<<" ";
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(8);
    root->right->right =  new Node(5);

    print_Inorder(root);
    cout<<endl;

    print_Preorder(root);
    cout<<endl;

    print_Postorder(root);
    cout<<endl;
    


}

