#include<iostream>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
Node* push(Node* head, int x)
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = head;
    head = new_node;
}
void print(Node *head)
{
    while(head!=NULL)
    {   
        cout<< "The Liked List is :: "
        cout<<head->data<<"<-";
        head = head->next;
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
     head = push(head,a);
    
    }
     print(head);
    return 0;
}