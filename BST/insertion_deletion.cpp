#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int key) {
        this->data = key;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* delete_key(Node* root, int key);

Node* insert_key(Node* root, int key) {

    if(root==NULL) {
        Node* new_Node = new Node(key);
        return new_Node;
    }

    if(root->data == key) {
        return root;
    }
    
    if(key < root->data) {
        root->left = insert_key(root->left, key);
    }
        
    
    if(key > root->data) {
        root->right = insert_key(root->right, key);
    }

    return root;
}


int delete_and_get_extreme_right_node(Node* root) {
    if(root->right) {
        while(root->right->right) {
            root = root->right;
        }
    }

    int temp = root->right->data;

    Node* temp_node = root->right->left;
    root->right->left = NULL;
    root->right = temp_node;
    
    return temp;
}


Node* delete_key(Node* root, int key) {

    if(root==NULL) {
        return root;
    }

    if(root->data==key) {
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        
        else if(root->left==NULL) {
            Node* temp = root->right;
            root->right = NULL;
            return temp; 
        }

        else if(root->right==NULL) {
            Node* temp = root->left;
            root->left = NULL;
            return temp;
            
        }
        else {
            int temp_data = delete_and_get_extreme_right_node(root->left);
            root->data = temp_data;
        }
    }

    else if(key > root->data) {
        root->right = delete_key(root->right, key);
    }

    else {
        root->left = delete_key(root->left, key);
    }

    return root;
}

void prinInorder(Node* root) {
    if(!root)   return;

    prinInorder(root->left);
    cout<<root->data<<" ";
    prinInorder(root->right);
}

int main() {

    Node* root = new Node(30);
    root->left = new Node(25);
    root->left->left = new Node(22);
    root->left->right = new Node(27);
    
    root->right = new Node(35);
    root->right->left = new Node(33);
    root->right->right = new Node(37);
    
    prinInorder(root);
    root = insert_key(root, 26);
    cout<<endl;
    prinInorder(root);

    root = delete_key(root, 22);
    cout<<endl;
    prinInorder(root);
    cout<<endl;
    cout<<"root->data: "<<root->data;

    return 0;
}

