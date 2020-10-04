int countNodesinLoop(struct Node *head)
{
    int exist = 0;
   
    if(head==NULL)
    {
        return 0;
    }
    Node *hare = head;
    Node *tor = head;
   while(tor&&hare&&hare->next) {
       hare=hare->next->next;
       tor=tor->next;
       if(tor==hare)
       {
          exist = 1;
          break;
       }
   }
    int count=0;
   if(exist)
   {
       Node* temp = head;
       while(temp!=hare)
       {
           count++;
           temp=temp->next;
       }
      return count;
   }
   else{
       return 1;
   }
}