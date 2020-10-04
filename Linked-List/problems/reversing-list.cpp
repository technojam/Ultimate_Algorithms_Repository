#include<iostream>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
void InLast(Node** head, int x)                 // Enter the node after the last node of the existing linked list...
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;
    if(*head==NULL)
    {
        *head = new_node;
    return;
    }
    
        Node* ptr = *head;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
         
         ptr->next=new_node;

}
void reverseList(Node** head)
{

    Node* prev = NULL;
    Node* cur = *head;
    Node* next = NULL;
    while(cur!=NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur =next;
        
    }
    *head = prev;
    
    
    
}
void print(Node *node)
{ 
    while(node!=NULL)
    {   
       
        cout<<node->data<<"<-";
        node = node->next;
    }
}
int main ()
{
    Node* head = NULL;
    int n;
    cout<<"Enter the Length of the list"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
     int a;
     cin>>a;
     InLast(&head,a);                                                                           // Write your own driver code here
    }
    cout<<"Printed list";
     print(head);
    reverseList(&head);
    cout<<"After reversing the list"<<endl;
    print(head);
    return 0;
}