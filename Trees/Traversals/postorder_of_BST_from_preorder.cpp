#include<iostream>

using namespace std;

/*
Time Complexity = O(N) where N is no. of nodes
Space Complexity = O(N) -> coz of function call stack size
*/

void PostOrderUtil(int pre[], int n, int minval, int maxval, int& preIndex) {
    if(preIndex==n)
        return;

    if(pre[preIndex] < minval || pre[preIndex] > maxval)
        return;
    
    int val = pre[preIndex];    //store current value to be pritned later
    preIndex++;

    PostOrderUtil(pre, n, minval, val, preIndex);

    PostOrderUtil(pre, n, val, maxval, preIndex);

    cout<<val<<" ";


}

void findPostOrder_BST(int pre[], int n) {

    int preIndex = 0;

    PostOrderUtil(pre, n, INT32_MIN, INT32_MAX, preIndex);

}

void getPostOrder_using_Pivot(int pre[], int n) {

    int pivotPoint = 0;

    // Find the index of element of right sub tree
    for(int i=1; i<n;i++) {
        if (pre[0] <= pre[i]) {
            pivotPoint = i;
            break;
        }
    }

    for(int i= pivotPoint-1; i>0;i--)
        cout<<pre[i]<<" ";
    
    for(int i=n-1; i>=pivotPoint; i--)
        cout<<pre[i]<<" ";

    cout<<pre[0];


}

int main() {

    // Brute Force Approach
    // Construct a BST from preOrder, then simply find the postOrder

    // Efficient Way is given below:
    
    int preOrder[] = {40, 30, 35, 80, 100};

    int n = sizeof(preOrder)/sizeof(preOrder[0]);
    findPostOrder_BST(preOrder, n);
    cout<<"\n";

    // A more efficient method is as below in which space is O(1)
    getPostOrder_using_Pivot(preOrder, n);

}