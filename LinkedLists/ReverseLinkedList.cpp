//Program to reverse of linked list using "ITERATIVE APPROACH".
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

//Function for traversing the linked list,
Node *traverse(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    return head;
}

//Function for reverse the nodes in linked list
Node *reverse(Node *head)
{
    Node *prevNode;
    Node *currentNode;
    Node *nextNode;
    prevNode = NULL;

    currentNode = nextNode = head; //Initially our these pointer is at starting same as head.

    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

int main()
{
    Node *head = NULL;
    Node *n2 = NULL;
    Node *n3 = NULL;
    Node *n4 = NULL;

    head = new Node();
    n2 = new Node();
    n3 = new Node();
    n4 = new Node();

    head->data = 34;
    head->next = n2;

    n2->data = 37;
    n2->next = n3;

    n3->data = 56;
    n3->next = n4;

    n4->data = 9;
    n4->next = NULL;

    head = reverse(head);
    traverse(head);
    return 0;
}