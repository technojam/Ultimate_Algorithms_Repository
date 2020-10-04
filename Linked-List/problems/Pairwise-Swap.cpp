Node* pairWiseSwap(struct Node* head) {
    
    Node* ptr = head;
   int x;
    while(ptr!=NULL && ptr->next!=NULL)
    {
       x=ptr->data;
       ptr->data=ptr->next->data;
       ptr->next->data=x;
       
       ptr=ptr->next->next;
    }
    
    return head;
    
}