#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    
    Node(int x){
        data=x;
        next=NULL;
        }
};

int maximum(Node *head)
{
    
    int max=0;
    struct Node *curr=head;
    while(curr!=NULL){
        if((curr->data)>=max){
            max=curr->data;
        }
        curr=curr->next;
    }
    return max;
}

int minimum(Node *head)
{
    
    int min=100000;
    struct Node *curr=head;
    while(curr!=NULL){
        if((curr->data)<=min){
            min=curr->data;
        }
        curr= curr->next;
    }
    return min;
}

int main()
{
    int data,n;
    cin>>n;
    cin>>data;
    struct Node *head= new Node(data);
    struct Node *tail= head;
    for(int i=0;i<n-1;i++){
        cin>>data;
        tail->next=new Node(data);
        tail=tail->next;
    }
    cout<<maximum(head)<<" "<<minimum(head)<<endl;
    return 0;
   
}