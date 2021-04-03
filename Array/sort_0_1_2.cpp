#include<iostream>

using namespace std;


void sort_012(int arr[], int n) {

    int sum_0 = 0;
    int sum_1 = 0;
    int sum_2 = 0;

    for(int i=0;i<n;i++) {

        if(arr[i]==0) {
            sum_0++;
        }

        if (arr[i]==1) {
            sum_1++;
        }

        if(arr[i]==2) {
            sum_2++;
        }

    }

    for(int i=0;i<n;i++) {
        if(i<sum_0)
            arr[i] = 0;
        
        else if(i>=sum_0 and (i-sum_0)<sum_1)
            arr[i] = 1;
        
        else if(i>=sum_0 && i>=sum_1 && (i-sum_0-sum_1) < sum_2)
            arr[i] = 2;
    }

    for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_using_swap_method(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high) {
        if(arr[mid]==0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid]==1) {
            mid++;
        }

        else if(arr[mid]==2) {
            swap(&arr[mid], &arr[high]);
            high--;
        }

    }

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }


}


int main() {

    int arr[] = {0,2,1,2,0,1,1,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // sort_012(arr,n);

    // cout<<endl;

    sort_using_swap_method(arr,n);

    return 0;
}