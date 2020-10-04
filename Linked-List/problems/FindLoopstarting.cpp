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
   if(exist)
   {
       tor = head;
       while(tor!=hare)
       {
           
           tor=tor->next;
       }
      return tor;
   }

}