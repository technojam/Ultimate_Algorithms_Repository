#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void create_ll(int*);                                    //FUNC to insert the elements in a Linked list
void display(int*);                                      //FUNC to display Linked list
void insert_beg(int*);                                   //FUNC to insert a node at the beginning
void insert_end(int*);                                   //FUNC to insert a node at the end of the Linked list
void insert_before(int*);                                //FUNC to insert a new node before the specified node
void insert_after(int*);                                 //FUNC to insert a new node after the specified node
void delete_beg(int*);                                   //FUNC to delete a node at the beginning
void delete_end(int*);                                   //FUNC to delete a node at the end of the Linked list
void delete_node(int*);                                  //FUNC to delete the specified node
void delete_after(int*);                                 //FUNC to delete a node after the specified node
void delete_list(int*);                                  //FUNC to delete the whole list
void sort_list(int*);                                    //FUNC to sort the node
void create_ll(struct node *start)
{
    struct node *new_node,*temp;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));              //defines the size of each node
        new_node -> data = num;
        if(start==NULL)
        {
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            temp = start;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new_node;
            new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d",&num);
    }
}

void display(struct node *start)
{
    struct node *temp;
    temp = start;
    printf("\n Linked List data :-\n ");
    if(start==NULL)                                         //If the first element is NULL,the list is empty
        printf(" Linked List is empty");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}

void insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    printf(" %d is inserted at the beginning of the list",new_node->data);

}

void insert_end(struct node *start)
{
    struct node *new_node,*temp;
    int num;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    temp = start;
    while(temp->next != NULL)                           //the loop will continue till it reches the end,that is where the Linked list is NULL
        temp = temp->next;
    temp->next = new_node;
    printf(" %d is inserted at the end of the list",new_node->data);

}

void insert_before(struct node *start)
{
    struct node *new_node,*preptr,*temp;
    int num,val;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    printf("\n Enter the value before which data has to be inserted : ");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    temp = start;
    while(temp->data != val)                              //The loop continues till the specified node is reached
    {
        preptr = temp;
        temp = temp->next;
    }
    preptr->next = new_node;
    new_node->next = temp;
    printf(" %d is inserted before %d",new_node->data,val);

}

void insert_after(struct node *start)
{
    struct node *new_node,*preptr,*temp;
    int num,val;
    printf("\n Enter the data : ");
    scanf("%d",&num);
    printf("\n Enter the value after which data has to be inserted : ");
    scanf("%d",&val);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    temp = start;
    while(preptr->data != val)                            //The loop continues till the specified node is reached
    {
        preptr = temp;
        temp = temp->next;
    }
    preptr->next = new_node;
    new_node->next = temp;
    printf(" %d is inserted after %d",new_node->data,val);

}

void delete_beg(struct node *start)
{
    struct node *temp;

    if(start == NULL)                                   //If the first element of the list is NULL,the list is empty
        printf(" Linked List is empty");
    else
    {
        temp = start;
        start = start->next;
        free(temp);
        printf(" Node deleted from the beginning");
    }
}

void delete_end(struct node *start)
{
    struct node *preptr,*temp;

    if(start == NULL)
        printf(" Linked List is empty");
    else
    {
        temp = start;
        if(temp->next == NULL)
        {
            start = delete_beg(start);
            return start;
        }
        else
        {
            while(temp->next != NULL)                                    //The loop will stop as soon as the end is reached
            {
                preptr = temp;
                temp = temp->next;
            }
            preptr->next = NULL;
            free(temp);
            printf(" Node deleted from the end");
        }
    }
}

void delete_node(struct node *start)
{
    struct node *preptr,*temp;
    int val;

    if(start == NULL)
        printf(" Linked List is empty");
    else
    {
        printf("\n Enter the value of node which has to be deleted : ");
        scanf("%d",&val);
        temp = start;
        if(temp->data == val)
        {
            start = delete_beg(start);
            return start;
        }
        else
        {
            while(temp->data != val)                            //The loop will stop as soon as the specified node is reached
            {
                preptr = temp;
                temp = temp->next;
            }
            preptr->next = temp->next;
            free(temp);
            printf(" Node is deleted");
        }
    }
}

void delete_after(struct node *start)
{
    struct node *preptr,*temp;
    int val;
    if(start == NULL)
        printf(" Linked List is empty");
    else
    {
        printf("\n Enter the value after which the node has to deleted : ");
        scanf("%d",&val);
        temp = start;
        preptr = temp;
        if(preptr->data == val)
        {
            temp = temp->next;
            preptr->next = temp->next;
        }
        else
        {
            while(preptr->data != val)
            {
                preptr = temp;
                temp = temp->next;
            }
            preptr->next = temp->next;
            free(temp);
            printf(" Node is deleted");
        }
    }
}

void delete_list(struct node *start)
{
    struct node *temp;

    if(start == NULL)
        printf(" Linked List is empty");
    else
    {
        if(start != NULL)
        {
            temp = start;
            while(temp != NULL)
            {
                printf("\n %d is to be deleted next",temp->data);
                start = delete_beg(temp);                 /*here we are calling a function which deletes elements from the beginning
                                                          so that elements can be deletd from the start and keep on deleting till the end is reached*/
              temp = start;                                   
            }
        }
    }
}

void sort_list(struct node *start)
{
    struct node *ptr1,*ptr2;
    int temp;
    ptr1 = start;
    if(start == NULL)
        printf(" Linked List is empty");
    else
    {
        while(ptr1->next != NULL)
        {
            ptr2 = ptr1->next;
            while(ptr2 != NULL)
            {
                if(ptr1->data > ptr2->data)                            //sorting through comparison of data
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        printf("\n List sorted");
    }
}
void main()                                                   //Main Function
{
   int option;
   printf("\n\n *****MAIN MENU******");
   printf("\n 1: Create a list");
   printf("\n 2: Display the list");
   printf("\n 3: Add a node at the beginning");
   printf("\n 4: Add a node at the end");
   printf("\n 5: Add a node before a given node");
   printf("\n 6: Add a node after a given node");
   printf("\n 7: Delete a node from the beginning");
   printf("\n 8: Delete a node from the end");
   printf("\n 9: Delete a given node");
   printf("\n 10: Delete a node after a given node");
   printf("\n 11: Delete the entire list");
   printf("\n 12: Sort the list");
   printf("\n 13: EXIT");
   do
   {

       printf("\n\n Enter your option : ");
       scanf("%d", &option);

       switch(option)
       {
            case 1:
                start = create_ll(start);
                printf("\n LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_node(start);
                break;
            case 10:
                start = delete_after(start);
                break;
            case 11:
                start = delete_list(start);
                break;
            case 12:
                start = sort_list(start);
                break;
       }
   }while(option != 13);
}
