#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

int search(int arr[], int x, int n) {

    for(int i=0;i<n;i++) {
        if(arr[i]==x)
            return i;
    }
    return -1;
}

void postOrder(int in[], int pre[], int n) {

    int root_index_in_inorder = search(in, pre[0], n);
    if(root_index_in_inorder != 0)
        postOrder(in, pre+1, root_index_in_inorder);
    
    if(root_index_in_inorder != n-1) 
        postOrder(in+root_index_in_inorder+1, pre+root_index_in_inorder+1, n- root_index_in_inorder - 1);

    cout<<pre[0]<<" ";

}

int main(){

    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // root->right = new Node(3);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    int in[] = { 4,2,5,1,6,3,7};
    int pre[] = {1,2,4,5,3,6,7};

    int n = sizeof(in)/sizeof(in[0]);

    postOrder(in, pre, n);


}