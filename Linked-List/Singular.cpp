#include<iostream>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
 Node* new_node = new Node();
void ins_bef_no(Node** head,int data, int pos_number)      // Enter the node ***before*** the position number/ given data number....
{
     Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    
    if(*head==NULL)
    { 
        *head = new_node;
        return;
    }
    
    Node *ptr = *head;
    Node *pre_ptr = *head;
    while(ptr->data!=pos_number)
    {
        pre_ptr=ptr;
        ptr=ptr->next;
    }
    pre_ptr->next = new_node;
    new_node->next = ptr;
    
}
void ins_After_no(Node** head,int data, int pos_number)      // Enter the node ***After*** the position number/ given data number....
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    
    if(*head==NULL)
    { 
        *head = new_node;
        return;
    }
    
    Node *ptr = *head;
    Node *pre_ptr = *head;
    while(ptr->data!=pos_number)
    {
        ptr=ptr->next;
    }
    
    pre_ptr=ptr;
    ptr=ptr->next;
    pre_ptr->next = new_node;
    new_node->next = ptr;
    
    
    
}
void push(Node** head, int x)                   // Enter the node before the existing list or node...
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = *head;
    *head = new_node;
}
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

void print(Node *node)
{ cout<< "The Liked List is :: ";
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
     cout<<"enter the data"<<" ";
     int d,e;
     cin>>d;
     cout<<"Enter the data from linked list"<<endl;
     cin>>e;
     ins_After_no(&head,d,e);
     print(head);
    return 0;
}