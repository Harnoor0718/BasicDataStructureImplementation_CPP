#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLL {
    Node* front;
    Node* rear;

public:
    QueueLL() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;
        if (!rear) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    QueueLL q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
