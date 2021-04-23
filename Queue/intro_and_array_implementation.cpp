#include<iostream>
#include<limits.h>

using namespace std;

/*
    Time Complexities:
        Enqueue         O(1)
        Dequeue         O(1)
        get front       O(1)
        get rear        O(1)
    
    Auxiliary Space : O(N)

Cons of Array Implementation:  

1.  Static Data Structure, fixed size.
2.  If the queue has a large number of enqueue and dequeue operations, 
    at some point we may not we able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue). 
*/

class Queue {
    public:
    int* array;
    int front, rear, size;
    unsigned capacity;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int data) {
    if(
        isFull(queue)) {
        cout<<"Queue is Full. Cannot append the new item: "<<data<<endl;
        return;
    }

    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = data;
    queue->size = queue->size+1;
    cout<<data<<" enqueued to Queue\n";
}

int dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        cout<<"Queue is empty. Can't remove anything\n";
        return INT_MIN;
    }

    int data = queue->array[queue->front];
    queue->front = (queue->front + 1)%(queue->capacity);
    queue->size = queue->size-1;
    return data;    
}

int front(Queue* queue) {
    if(isEmpty(queue)) {
        return INT_MIN;
    }

    return queue->array[queue->front];
}

int rear(Queue* queue) {
    if(isEmpty(queue))
        return INT_MIN;
    
    return queue->array[queue->rear];
}

int main() {
    Queue* queue = createQueue(1000);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout<<  dequeue(queue)
        <<  " dequeued from Queue\n";
    
    cout<< "Front item is: "
        <<  front(queue) << endl;
    
    cout<< "Rear item is: "
        <<  rear(queue) <<  endl;
    
    return 0;

}