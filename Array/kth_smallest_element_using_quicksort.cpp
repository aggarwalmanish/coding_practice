#include<iostream>
#include<algorithm>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {

    int x = arr[r];
    int i = l;
    
    
    for(int j=l;j<=r-1;j++) {
        if(arr[j]<=x) {
            swap(&arr[i], &arr[j]);
            i++;
        }

    }
    swap(&arr[i], &arr[r]);

    return i;

}

int kthsmallest_element(int arr[], int l, int r, int k) {

    if(k>0 and k<=(r-l+1)) {
        int pos = partition(arr, l, r);
        if ((pos-l) == (k-1)) {
            return arr[pos];
        }
        if (pos-l > k-1) 
            return kthsmallest_element(arr, l, pos-1, k);
        
        return kthsmallest_element(arr, pos+1, r, k-(pos-l)-1);
    }

    return INT32_MAX;

}

int simple_kthsmallest(int arr[], int n, int k) {

    sort(arr, arr+n);
    return arr[k-1];
}

int main() {

    int arr[] = {7, 10, 4, 3, 20, 15};
    int arr_size = 6;
    int k = 3;      // find kth smallest element from the array which should give us 15

    // simple way is to loop the complete array k times, where in each loop
    // we store the leftest element as the minimum of the whole array, then loop on 
    // the left+1 to right array, and then find its minimum and store it at [l+1] index
    // like this we do k times, and then we return the arr[left] of that array
    // but it'll take O(n*k) time which will result in TLE

    // so, other ways are
    // 1. Min heap      -> O(n + klogn)
    // 2. Quick Sort (pivot til kth smallest ele) -> O(n) average; O(n^2) in worst case
    // 3. Sort and return the [k-1] element     -> O(n*logn)
    
    cout<<kthsmallest_element(arr, 0, arr_size-1, k)<<endl;

    cout<<"Using simple sorting: O(n) = N*logN : "<<simple_kthsmallest(arr,arr_size, k);


}