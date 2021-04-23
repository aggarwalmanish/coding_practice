#include<iostream>

using namespace std;

void RearrangeNegPos(int arr[], int n) {

    int key, j;
    for(int i=1;i<n;i++) {
        key = arr[i];

        if (key>0)
            continue;
        
        j = i-1;
        while(j>=0 && arr[j]>0) {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}

int main() {

    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    RearrangeNegPos(arr, n);        // This is a modified Insertion sort with time complexity as O(n^2) and aux space as O(1)
    
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;

}