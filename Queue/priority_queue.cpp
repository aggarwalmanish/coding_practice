#include<iostream>

using namespace std;


/*

it can be implemented with Array :
    struct item {
        int data;
        int priority
    };
then making an array with this <item> type instead of int (using vector).
it will take    O(n) time to getHighestPriority() item from the queue.
                O(1) time to insert item into the queue.
                O(n) time to delete_HighestPriority() item from the queue (as it will include searching for the index, then moving all subsequent items one position back)


Similarly we can also, implement it using linked list, where the difference will be that here while deleting_Highest_Priority() we DON'T need to move all subsequent items one position back

And the most efficient will be using Heap:
it will take    O(1) to get_Highest_Priority()
                O(Log N) to insert item into the queue.                 {{ insert can be done in O(1) as well in case of Fibonacci Heap}}
                O(Log N) to delete Highest Priority Item
*/



int main() {


}