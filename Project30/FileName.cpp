#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;         
    Node* next;     

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* head; 

public:
    Stack() : head(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "Error: Attempt to pop from an empty stack!" << endl;
            return false;  
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return true;  
    }

    T top() const {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return T(); 
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "The stack is empty." << endl;
    }

    if (!stack.pop()) {
        cout << "Failed to pop: The stack is already empty." << endl;
    }

    return 0;
}
