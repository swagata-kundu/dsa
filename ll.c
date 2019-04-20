#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

void printLinkedList(node_t *start)
{
    while (start != NULL)
    {
        printf("%d, ", start->val);
        start = start->next;
    }
    printf("\n");
}

void push(int item, node_t **start)
{
    node_t *new_node;
    new_node = malloc(sizeof(node_t));
    new_node->val = item;
    new_node->next = *start;
    *start = new_node;
}

void addItemAtLast(node_t *head, int value)
{
    while (head->next != NULL)
    {
        head = head->next;
    }

    node_t *newNode = NULL;
    newNode = malloc(sizeof(node_t));
    newNode->val = value;
    newNode->next = NULL;
    head->next = newNode;
}

int pop(node_t **start)
{
    if (*start == NULL)
    {
        return -1;
    }
    node_t *next_node = (*start)->next;
    int popped_item = (*start)->val;

    free(*start);
    *start = next_node;
    return popped_item;
}

void removeLastElement(node_t *start)
{
    if (start == NULL)
    {
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        return;
    }

    node_t *current_node = start;
    node_t *prev = start;

    while (current_node->next != NULL)
    {
        node_t *temp = current_node;
        current_node = current_node->next;
        prev = temp;
    }
    printf("%d \n", prev->val);
    free(prev->next);
    prev->next = NULL;
}

int removeNthElement(node_t **start, int index)
{
    node_t *head = *start, *prevNode = *start;
    if (head == NULL)
    {
        return -1;
    }
    if (index == 1)
    {
        node_t *nodeToDelete = *start;
        int value = nodeToDelete->val;
        *start = (*start)->next;
        free(nodeToDelete);
        return value;
    }
    int currentIndex = 2;
    head = head->next;
    while (currentIndex != index && head != NULL)
    {
        prevNode = head;
        head = head->next;
        currentIndex++;
    }

    if (head == NULL)
    {
        return -1;
    }

    node_t *nodeToDelete = head;
    int value = nodeToDelete->val;
    prevNode->next = head->next;
    nodeToDelete->next = NULL;
    free(nodeToDelete);
    return value;
}

int findLength(node_t *start)
{
    if (start == NULL)
    {
        return 0;
    }
    if (start->next == NULL)
    {
        return 1;
    }

    return 1 + findLength(start->next);
}

bool findItem(node_t *head, int item)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->val == item)
    {
        return true;
    }
    return false || findItem(head->next, item);
};

int findNthNodeLast(node_t *head, int index, int *item)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
    {
        if (index == 1)
        {
            *item = head->val;
        }
        return 1;
    }

    int currentIndex = findNthNodeLast(head->next, index, item) + 1;

    if (currentIndex == index)
    {
        *item = head->val;
    }

    return currentIndex;
}

int findMidElement(node_t *head)
{
    if (head == NULL)
    {
        return -1;
    }
    node_t *slowPointer = head;

    while (head != NULL && head->next != NULL)
    {
        head = head->next->next;
        slowPointer = slowPointer->next;
    }

    return slowPointer->val;
}

void recursiveReverse(node_t *curretList, node_t **reverseList)
{
    if (curretList->next == NULL)
    {
        *reverseList = curretList;
    }
    else
    {
        recursiveReverse(curretList->next, reverseList);
        curretList->next = NULL;

        node_t *temp = *reverseList;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = curretList;
        int a = 1;
    }
}

void reverse(node_t **start)
{
    node_t *reversedList = NULL;

    if (start == NULL)
    {
        return;
    }
    recursiveReverse(*start, &reversedList);
    *start = reversedList;
}

void swapNode(node_t **start)
{
    if (*start && (*start)->next)
    {
        node_t *tmp = *start;
        *start = (*start)->next;
        tmp->next = (*start)->next;
        (*start)->next = tmp;
        swapNode(&(tmp->next));
    }
}

void r(node_t **start, node_t *curNode)
{
    if (curNode->next && !(curNode->next)->next)
    {
        node_t *lastNode = curNode->next;
        lastNode->next = *start;
        *start = lastNode;
        curNode->next = NULL;
    }
    else
    {
        r(start, curNode->next);
    }
}
void moveLastNodeToTop(node_t **start)
{
    r(start, *start);
}

node_t *interSection(node_t *l1, node_t *l2)
{

    if (!l1 || !l2)
    {
        return NULL;
    }

    if (l1->val < l2->val)
    {
        return interSection(l1->next, l2);
    }
    if (l1->val > l2->val)
    {
        return interSection(l1, l2->next);
    }

    node_t *newNode = malloc(sizeof(node_t));
    newNode->val = l1->val;
    newNode->next = interSection(l1->next, l2->next);
    return newNode;
}

int main()
{
    node_t *h1 = NULL, *h2 = NULL;

    push(3, &h1);
    push(3, &h2);

    addItemAtLast(h1, 4);
    addItemAtLast(h1, 10);
    addItemAtLast(h1, 16);
    addItemAtLast(h1, 71);
    addItemAtLast(h1, 98);

    addItemAtLast(h2, 5);
    addItemAtLast(h2, 10);
    addItemAtLast(h2, 15);
    addItemAtLast(h2, 71);
    addItemAtLast(h2, 81);

    printLinkedList(h1);
    printLinkedList(h2);

    node_t *intersect = interSection(h1, h2);
    printLinkedList(intersect);
}
