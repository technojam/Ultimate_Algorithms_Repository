#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
void push(Node** head, int x)                  // IS LINKED LIST A isPalindrome
{
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = *head;
    *head = new_node;
}

bool isPalindrome(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    stack<int>s;
    Node* nibba = head;
    while(nibba!=NULL)
    {
        s.push(nibba->data);
        nibba = nibba->next;
    }
    
    while(head!=NULL)
    {
        if(head->data!=s.top())
        {
            return 0;
        }
        s.pop();
        head= head->next;
        
    }
    return 1;
    
}
int main ()
{
    Node* head = NULL;
 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
  
    // write your own driver ap[p]  👈👈👨‍💻
      
  
    return 0; 
}