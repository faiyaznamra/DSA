#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack.\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!\n";
            return;
        }
        Node *temp = top;
        cout << temp->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        Node *current = top;
        cout << "Stack: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element is: " << s.peek() << "\n";
    s.pop();
    s.display();
    return 0;
}