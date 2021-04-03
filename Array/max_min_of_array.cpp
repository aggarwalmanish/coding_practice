#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

// Find the maximum and minimum using min number of comparisons
// Now here, T(n) = O(n) but it is about how much times n, like 2n or 3n/2 

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax_linear(int arr[], int n) {
    

    struct Pair minmax;

    // if there is only one element, then return it as min and max both
    if(n==1) {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }

    if(arr[0] > arr[1]) {
        minmax.min = arr[1];
        minmax.max = arr[0];
    }
    else {
        minmax.min = arr[0];
        minmax.max = arr[1];
    }

    for(int i=2;i<n;i++) {
        if(arr[i]<minmax.min)
            minmax.min = arr[i];
        
        if (arr[i]>minmax.max)
            minmax.max = arr[i];
    }

    // Thats in worst case : 2*(n-2) + 1 comparisions
    return minmax;
}

struct Pair getMinMax_tournament_method(int arr[], int low, int high) {
    struct Pair minmax;
    int i;

    if(low==high){
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }

    if(high-low == 1) {
        if(arr[low]<arr[high]) {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        else {
            minmax.min = arr[high];
            minmax.max = arr[low];
        }
        return minmax;
    }

    int mid = (low+high)/2;
    struct Pair mml = getMinMax_tournament_method(arr,low,mid);
    struct Pair mmr = getMinMax_tournament_method(arr,mid+1,high);

    if(mml.min < mmr.min)
        minmax.min = mml.min;
    else
    {
        minmax.min = mmr.min;
    }

    if(mml.max>mmr.max) {
        minmax.max = mml.max;
    }
    else
    {
        minmax.max = mmr.max;
    }

    return minmax;
    // In worst case: it'll do 
    // T(n) = 2T(n/2) + 2       (Divide and Conquer ALGO)
    // thats = 3n/2 -2 if n is a power of 2
    //          more than 3n/2 - 2 if n is not a power of 2
    
}

struct Pair getMinMax_by_comparing_in_pairs(int arr[], int n) {
    struct Pair minmax;
    int i;

    // if n is even then initialize first 2 elements as min and max

    if(n%2==0) {
        if(arr[0] > arr[1]) {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else{
            minmax.max = arr[1];
            minmax.min = arr[0];
        }

        i = 2;      // setting starting index as 2 in case of even no. of elements
    }

    else {
        minmax.min = arr[0];
        minmax.max = arr[1];
        i = 1;      //setting starting index as 1 in case of odd no. of elemnents
    }

    while(i<n-1) {
    if(arr[i] > arr[i+1]) {
        if(arr[i] > minmax.max)
            minmax.max = arr[i];
        
        if(arr[i+1] < minmax.min)
            minmax.min = arr[i+1];
    }
    else {
        if(arr[i] < minmax.min)
            minmax.min = arr[i];
        
        if(arr[i+1] > minmax.max)
            minmax.max = arr[i+1];
    }

    i += 2;
    }
    return minmax;

    // Here in worst case,
    // If even :    T(n) = 1 + 3*(n-2)/2 = 3n/2 - 2
    // If odd :     T(n) = 3*(n-1)/2

    // So, in even case it has same comparisons as in method 2 but in odd case
    // it has fewer comparisions, so this is best method

}



void print_output(struct Pair minmax) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    cout<<"Min: "<<minmax.min<<endl;
    cout<<"Max: "<<minmax.max<<endl;

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout<<"Total time taken: "<<cpu_time_used<<setprecision(5)<<endl;

}
int main() {

    int arr[] = {1000, 11, 445, 745, 416, 444, 658, 6777, 741};
    int arr_size = 9;

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    struct Pair minmax1 = getMinMax_linear(arr, arr_size);
    cout<<"Min: "<<minmax1.min<<endl;
    cout<<"Max: "<<minmax1.max<<endl;

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout<<"Total time taken: "<<cpu_time_used<<setprecision(5)<<endl;

    // Method 2
    
    start = clock();

    struct Pair minmax2 = getMinMax_by_comparing_in_pairs(arr,arr_size);
    cout<<"Min: "<<minmax2.min<<endl;
    cout<<"Max: "<<minmax2.max<<endl;

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout<<"Total time taken: "<<cpu_time_used<<setprecision(5)<<endl;


    // Method 3
    start = clock();
    struct Pair minmax3 = getMinMax_tournament_method(arr, 0, arr_size-1);
    cout<<"Min: "<<minmax3.min<<endl;
    cout<<"Max: "<<minmax3.max<<endl;

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout<<"Total time taken: "<<cpu_time_used<<setprecision(5)<<endl;

    return 0;
}
