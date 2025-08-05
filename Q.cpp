#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }
    void peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }
    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.peek();
    return 0;
}