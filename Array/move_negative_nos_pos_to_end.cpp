#include<iostream>

using namespace std;

void move_neg_to_beg_and_pos_to_end(int arr[], int n) {

    int low = 0;
    int mid = 0;
    int high = n-1;
    
    int temp;

    while(mid<=high) {
        if(arr[mid]<0){
            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }

        else if(arr[mid]>0) {
            temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

void swap(int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_pos_neg(int arr[], int n) {

    int pivot = 0;
    int i = 0;

    for(int j=0;j<=n-1;j++) {
        if(arr[j]<0) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[n-1]);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // move_neg_to_beg_and_pos_to_end(arr,n);

    sort_pos_neg(arr,n);
    return 0;
}