void deleteNode(Node **head_ref, int x)
{
    Node *ptr = *head_ref;

    
   for(auto i=0;i<x-1;i++)
   { 
        ptr=ptr->next;
        
   }
   if(ptr->next==NULL)
   {
       ptr->prev->next=NULL;
       free(ptr);
   }
   else if(x==1)
   {
       *head_ref= (*head_ref)->next;
        (*head_ref)->prev=NULL;
        free(ptr);
   }
   else {
       ptr->prev->next=ptr->next;
       ptr->next=ptr->prev;
       free(ptr);
   }
  
}