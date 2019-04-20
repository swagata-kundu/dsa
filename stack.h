class StackNode
{
public:
    int data;
    StackNode *next;
};

class Stack
{
public:
    Stack();
    void push(int data);
    int pop();
    bool isEmpty();
    bool isLastElement();

private:
    StackNode *head;
    StackNode *newNode(int data);
};