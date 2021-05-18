#include<iostream>
#include<limits.h>
using namespace std;

/*
    Time complexity of all operations i.e. insert, delete or get is O(1)
*/

class Dequeue {

    int front, rear, size;
    int arr[100];
    public:
        Dequeue(int size) {
            front = -1;
            rear = 0;
            this->size = size;
        }
        bool isFull();
        bool isEmpty();
        void insert_at_front(int key);
        void insert_at_rear(int key);
        void delete_at_front();
        void delete_at_rear();
        int get_front();
        int get_rear();
};

int Dequeue::get_front() {
    if(!isEmpty()) {
        return arr[front];
    }
    return INT_MIN;
}

int Dequeue::get_rear() {
    if(!isEmpty()) {
        return arr[rear];
    }
    return INT_MIN;
}

bool Dequeue::isFull() {
    if((front==0 && rear==size-1) || (front == rear+1)) {
        cout<<"Dequeue is full\n";
        return true;
    }
    return false;
}

bool Dequeue::isEmpty() {
    if(front==-1) {
        cout<<"Dequeue is Empty\n";
        return true;
    }
    return false;
}

void Dequeue::insert_at_front(int key) {

    if(isFull()) {
        cout<<"Overloaded.\n";
        return;
    }

    if(front==-1) {
        front = 0;
        rear = 0;
    }

    else if(front==0) {
        front = size-1;
    }

    else {
        front = front - 1;
    }

    arr[front] = key;
}

void Dequeue::insert_at_rear(int key) {

    if(isFull()) {
        cout<<"Overloaded\n";
        return;
    }

    if(front==-1) {
        front=0;
        rear=0;
    }
    else if(rear=size-1) {
        rear=0;
    }
    else {
        rear = rear+1;
    }

    arr[rear] = key;

}

void Dequeue::delete_at_front() {
    if(isEmpty()) {
        cout<<"Queue  is Empty\n";
        return;
    }

    if(front==rear) {
        front = -1;
        rear = -1;
    }

    else if (front==size-1){
        front=0;
    }

    else {
        front = front+1;
    }
}

void Dequeue::delete_at_rear() {
    if(isEmpty()) {
        cout<<"Dequeue is Empty\n";
        return;
    }
    if(rear==front) {
        rear = -1;
        front = -1;
    }

    else if (rear == 0) {
        rear = size-1;
    }

    else {
        rear = rear - 1;
    }
}

int main() {

    Dequeue q(100);
    cout<<q.get_front()<<endl;
    q.insert_at_front(10);
    q.insert_at_front(20);
    cout<<q.get_front()<<endl;
    q.delete_at_front();
    cout<<q.get_front()<<endl;
    return 0;

}