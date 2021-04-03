#include<iostream>
#include<vector>

using namespace std;

/*
The problem here is that we have to print the pre-order traversal of all the possible binary trees
of the given inOrder traversal array

Solution:
Firstly we create a list of all possible trees from inorder then do their preOrder traversal
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int val) {
        this->data = val;
        left = right = NULL;
    }
};

vector<Node*> getTrees(int inorder[], int start, int end) {

    vector <Node*> trees;
    
    if(start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++) {
        vector<Node*> ltrees = getTrees(inorder, start, i-1);
        vector<Node*> rtrees = getTrees(inorder, i+1, end);

        for(int j=0; j< ltrees.size(); j++) {
            for(int k=0; k< rtrees.size(); k++) {

                Node* newNode = new Node(inorder[i]);
                newNode->left = ltrees[j];
                newNode->right = rtrees[k];

                trees.push_back(newNode);
            }
        }
    }

    return trees;
}


void print_preOrder(Node* root) {

    if (root==NULL)
        return;
        
    cout<<root->data<<" ";
    print_preOrder(root->left);
    print_preOrder(root->right);
}

int main() {

    int inOrder[] = {4,5,7};
    int n = sizeof(inOrder)/sizeof(inOrder[0]);
    vector<Node*> trees = getTrees(inOrder, 0, n-1);

    for(int i=0;i<trees.size(); i++) {
        print_preOrder(trees[i]);
        cout<<"\n";
    }
    return 0;
}