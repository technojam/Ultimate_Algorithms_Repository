#include <iostream>
using namespace std;
struct Node     //Node Creation
{
    int data;
    struct Node *next;
};
void insertBeg(struct Node** head, int node_data)/*insert a new node in front of the list */
{
   struct Node* newNode = new Node;        /* 1. create and allocate node */
   newNode->data = node_data;              /* 2. assign data to node */
   newNode->next = (*head);                /* 3. set next of new node as head */
   (*head) = newNode;                      /* 4. move the head to point to the new node */
}

void insertAfter(struct Node* prev_node, int node_data)//Insert New Node after a Given Node
{
    if (prev_node == NULL)                  /*1. check if the given prev_node is NULL */
    {
        cout<<"The given previous node is required,cannot be NULL";
        return; 
    } 
    struct Node* newNode =new Node;         /* 2. create and allocate new node */
    newNode->data = node_data;              /* 3. assign data to the node */
    newNode->next = prev_node->next;        /* 4. Make next of new node as next of prev_node */
    prev_node->next = newNode;              /* 5. move the next of prev_node as new_node */
}

void insertEnd(struct Node** head, int node_data)  /* insert new node at the end of the linked list */
{
    struct Node* newNode = new Node;    /* 1. create and allocate node */
    struct Node *last = *head;          
    newNode->data = node_data;          /* 2. assign data to the node */
    newNode->next = NULL;               /* 3. set next pointer of new node to null as its the last node*/
    if (*head == NULL)                  /* 4. if list is empty, new node becomes first node */
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)          /* 5. Else traverse till the last node */
    last = last->next;
    last->next = newNode;               /* 6. Change the next of last node */
    return;
}
void displayList(struct Node *node)     // Display Linked List
{
   
   while (node != NULL)                 //Traverse the list to display each node
   {
       cout<<node->data<<"-->";
       node = node->next;
   }
 
    if(node== NULL)
        cout<<"NULL"; 
} 

int main()            //Main Program
{ 
    struct Node* head = NULL;   /* empty list */
    insertEnd(&head, 10);       // Insert 10.
    insertBeg(&head, 20);       // Insert 20 at the beginning. 
    insertBeg(&head, 30);       // Insert 30 at the beginning. 
    insertEnd(&head, 40);       // Insert 40 at the end. 
    insertAfter(head->next, 50);//Insert 50, after 20.
    cout<<"Final Linked List: "<<endl;
    displayList(head);
    return 0;
}