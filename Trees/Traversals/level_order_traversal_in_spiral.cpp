#include<iostream>
#include<queue>
#include <stack>
using namespace std;

/*
        1
    2       3
 7     6  5    4

 print like "1 2 3 4 5 6 7" 

*/


struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
};


int tree_height(Node* root) {

    if (root==NULL)
        return 0;
    
    int l_height = tree_height(root->left);
    int r_height = tree_height(root->right);

    if(l_height > r_height)
        return l_height + 1;
    else
    {
        return r_height + 1;
    }
    
}

void printGivenLevel(Node* root, int level, int dir) {

    if(level==1){
        cout<<root->data<<" ";
        return;
    }

    if (dir>0) {
        printGivenLevel(root->left, level-1, dir);
        printGivenLevel(root->right, level-1, dir);
        
    }

    else {
        printGivenLevel(root->right, level-1, dir);    
        printGivenLevel(root->left, level-1, dir); 
    } 

}

void printLevelOrderSpiral_new(Node* root) {

    // Time complexity of this method is O(n^2)
    // Worst case will occue in case of skewed trees

    int height = tree_height(root);
    int dir = 1;
    cout<<root->data<<" ";

    for(int level = 2; level<=height; level++) {
        printGivenLevel(root, level, dir);
        dir = dir*(-1);
    }


}


void printLevelOrderinSpiral(Node* root) {

    // This method gives wrong output
    // But there is another method like this which uses 2 stacks given below by
    // printSpiral_iterative()

    if(root== NULL)
        return;

    queue<Node*> q;
    q.push(root);
    int count = 1;

    while(!q.empty()) {

        Node* temp = q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(count > 0) {
            if(temp->left)
                q.push(temp->left);
        
            if(temp->right)
                q.push(temp->right);   
        }

        else {
            if(temp->right)
                q.push(temp->right);   
            
            if(temp->left)
                q.push(temp->left);
        }
        count = count*-1;
    }
}


void printSpiral_iterative(Node* root){

    stack<Node*> s1;    // This stack will be used to print elements from right to left 
    stack<Node*> s2;    // This stack will be used to print elements from left to right

    s1.push(root);

    while(!s1.empty() || !s2.empty()) {

        
    }


}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);
    root->right->left = new Node(5);
    root->left->right = new Node(6);
    root->left->left = new Node(7);

    printLevelOrderinSpiral(root);      // This function did not worked and returned a wrong output

    cout<<"New way: \n";
    printLevelOrderSpiral_new(root);

    return 0;
}