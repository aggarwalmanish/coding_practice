#include<iostream>

using namespace std;



struct QNode {

    int data;
    QNode* next;
    QNode (int d) {
        data = d;
        next = NULL;
    }
};

struct Queue {

    QNode *front, *rear;
    Queue() {
        front = rear = NULL;
    }

    void enQueue(int x) {
        QNode* temp = new QNode(x);

        if(rear==NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void deQueue() {

        if(front==NULL)
            return;

        QNode* temp = front;
        front = front->next;
        temp->next = NULL;

        if(front==NULL) {
            rear = NULL;
        }

        delete(temp);

    }

};

int main() {


    Queue q;
    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(15);
    q.deQueue();
    cout<<"Queue front is: "<<(q.front)->data<<endl;
    cout<<"Queue Rear is: "<<(q.rear)->data<<endl;

    return 0;

}