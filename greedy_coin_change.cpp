#include<iostream>
#include<algorithm>

using namespace std;


int coinChange(int arr[], int target, int n) {

    if(target<=0) {
        return 0;
    }

    cout<<"n: "<<n<<endl;
    
    sort(arr, arr+n, greater<int>());

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int coins = 0;
    int curr_coins = 0;
    for(int i=0;i<n;i++) {
        if(arr[i]<=target) {
            curr_coins = (target/arr[i]);
            coins += curr_coins;
            target = target - arr[i]*curr_coins;
            cout<<"Coins required of deno: "<<arr[i]<<" are: "<<curr_coins<<endl;
        }
    }

    return coins;

}

int main() {

    int arr[] = {10,50,2,5,1,20,2000,200,500,100};
    int target = 459;

    int n = sizeof(arr)/sizeof(arr[0]);

    int coins = coinChange(arr, target, n);
    cout<<"Final result : "<<coins<<endl;
    return 0;

}