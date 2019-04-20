#include <iostream>
#include "stack.cpp"

using namespace std;

class Queue
{
    Stack *st1, *st2;

public:
    Queue()
    {
        st1 = new Stack();
        st2 = new Stack();
    }

    void enQueue(int data)
    {
        st1->push(data);
        cout << "Queued item " << data << endl;
    }

    bool isEmpty()
    {
        return st1->isEmpty() && st2->isEmpty();
    }

    int deQueue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int elem = recursive(st1->pop());
        return elem;
    }

    int recursive(int data)
    {
        if (st1->isEmpty())
        {
            return data;
        }
        int result = recursive(st1->pop());
        st1->push(data);
        return result;
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);

    while (!q.isEmpty())
    {
        cout << q.deQueue() << endl;
    }
    cout << q.deQueue() << endl;
}