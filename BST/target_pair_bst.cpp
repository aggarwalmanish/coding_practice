#include<iostream>
#include<stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

pair<int, int> find_pair_target(Node* root, int target) {

    pair<int, int> p;
    if(root==NULL)  return p;

    stack<Node*> s1;
    stack<Node*> s2;

    Node* temp = root;
    while(temp!=NULL) {
        s1.push(temp);
        temp = temp->left;
    }

    temp = root;
    while(temp!=NULL) {
        s2.push(temp);
        temp = temp->right;
    }

    while(!s1.empty() || !s2.empty()) {
        int sum = s1.top()->data + s2.top()->data;
        if(sum == target) {
            p.first = s1.top()->data;
            p.second = s2.top()->data;
            return p;
        }

        if(sum > target) {
            temp = s2.top();
            s2.pop();

            temp = temp->left;
            while(temp!=NULL) {
                s2.push(temp);
                temp = temp->right;
            }
        }

        if(sum < target) {
            temp = s1.top();
            s1.pop();

            temp = temp->right;
            while(temp!=NULL) {
                s1.push(temp);
                temp = temp->left;
            }
        }
    }

    return p;
}

void print_inorder(Node* root) {
    if(root==NULL)  return;

    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
int main() {

    Node* root = new Node(70);
    root->left = new Node(50);
    root->left->left = new Node(40);
    root->left->left->left = new Node(30);
    root->left->right = new Node(60);
    root->left->right->left = new Node(55);
    root->right = new Node(80);
    root->right->right = new Node(90);

    print_inorder(root);
    cout<<endl;
    
    int target = 2000;
    pair<int, int> result = find_pair_target(root, target);

    if(result.first && result.second) {
        cout<<"first element: "<<result.first<<endl;
        cout<<"second element: "<<result.second<<endl;
    }
    else {
        cout<<"No pair found";
    }

    return 0;
}