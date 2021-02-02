#include<iostream>
#include<queue>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* delete_last_node(Node* root, Node* d_node) {

    if(root == NULL || d_node == NULL) {
        return NULL;
    }
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        if(temp->data == d_node->data) {
            temp = NULL;
            temp->left = temp->right = NULL;
            return NULL;
        }

        if(temp->left) {
            if(temp->left->data == d_node->data) {
                temp->left = NULL;
                delete (d_node);
                return NULL;
            }
            else
            {
                q.push(temp->left);
            }
            
        }

        if(temp->right) {
            if(temp->right->data == d_node->data) {
                temp->right = NULL;
                delete (d_node);
                return NULL;
            }
            else
            {
                q.push(temp->right);
            }
            
        }
    }

    return NULL;
}

Node* delete_and_replace_last_node(Node* root, int delete_data) {

    int last_node_data;

    if (root == NULL) {
        return NULL;
    }

    queue<Node*> q;
    q.push(root);

    Node* to_delete_node = NULL;
    Node* temp;

    while(!q.empty()) {

        temp = q.front();
        q.pop();


        if(temp->data == delete_data) {
            to_delete_node = temp;
        }

        if(temp->left) {
            q.push(temp->left);
        }

        if(temp->right) {
            q.push(temp->right);
        }

    }

    if(to_delete_node!= NULL) {
        int last_node_data = temp->data;
        delete_last_node(root, temp);
        to_delete_node->data = last_node_data;
    }

    return root;

}

void inOrder(Node* root) {

    if (root== NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

int main() {

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->right = new Node(40);

    inOrder(root);
    cout<<endl;

    delete_and_replace_last_node(root, 10);  

    inOrder(root);


    return 0;
}

