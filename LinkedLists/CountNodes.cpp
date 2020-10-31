#include <iostream>
using namespace std;

struct Node{         // Node declaration
    int data;   
    struct Node *next;
    
    Node(int x){
        data=x;
        next=NULL;
        }
};

int CountElements(Node *head){    // Count function
    
    int count=0;
    
    struct Node *curr= head;   // Creating a new pointer curr to store address of head
    while(curr!=NULL){   //traversing till the end of linked list throught curr pointer
        curr=curr->next;
        count++;  // incrementing count to count number of nodes traversed
    }
    return count;
}

int main()
{
    int data,n;  
    cin>>n;   // number of elements in linked list
    cin>>data;
    struct Node *head= new Node(data);
    struct Node *tail= head;
    for(int i=0;i<n-1;i++){
        cin>>data;   // taking input of values of linked list
        tail->next=new Node(data);
        tail=tail->next;
    }
    cout<<CountElements(head)<<endl;
    return 0;
   
}
