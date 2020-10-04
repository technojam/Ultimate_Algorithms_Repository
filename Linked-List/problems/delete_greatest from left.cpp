Node *compute(Node *head)
{
        if(head->next==NULL)
        return head;
        struct Node *temp=compute(head->next);
        if(temp->data > head->data)
        return temp;
        else
        head->next=temp;
        return head;
}