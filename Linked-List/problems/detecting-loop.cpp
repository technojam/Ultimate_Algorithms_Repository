#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
void push(Node** head, int x)                   // Detect Loop in the linked list  ,,...,,
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = *head;
    *head = new_node;
}

bool detectLoop(Node * head)
{
   unordered_set<Node*> s; 
    while(head!=NULL)
    {
        if(s.find(head)!=s.end())
        return true;
        s.insert(head);
        head=head->next;
    }
    return false;
}
int main ()
{
    Node* head = NULL;
 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
  
    /* Create a loop for testing */
    head->next->next->next->next = head; 
  
    if (detectLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
  
    return 0; 
}