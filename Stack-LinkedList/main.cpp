#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StackLL {
    Node* top;

public:
    StackLL() { top = nullptr; }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackLL s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    s.pop();
    s.display();
    return 0;
}
