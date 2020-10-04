int getMiddle(Node *head)
{  
    if(head==NULL)
    {
        return -1;
    }
    Node* ptr = head;
    int t =0;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        t++;
    }
    Node* get = head;
    if(t%2==0)
    {
    for(int i=0;i<t/2;i++)
    {
        get = get->next;
    }
    }
    else {
         for(int i=0;i<(t+1)/2;i++)
    {
        get=get->next;
    }
    }
    return get->data;
   // Your code here
}
