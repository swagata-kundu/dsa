#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void push(int data);
    void print();
};
void List::push(int data)
{
    Node *newNode = new Node();
    newNode->data = data;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void List::print()
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void List::print()
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

int main()
{
    List l;
    l.push(10);
    l.push(100);
    l.push(20);
    l.print();
}
