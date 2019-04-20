#include "stack.h"
Stack ::Stack()
{
    head = NULL;
}

StackNode *Stack::newNode(int data)
{
    StackNode *node = new StackNode();
    node->data = data;
    node->next = NULL;
    return node;
}

bool Stack::isEmpty()
{
    return !head;
}

void Stack::push(int data)
{
    StackNode *elem = newNode(data);
    elem->next = head;
    head = elem;
}

int Stack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    StackNode *top = head;
    head = head->next;
    int elem = top->data;
    delete top;
    return elem;
}

bool Stack::isLastElement() {
    return !head->next;
}