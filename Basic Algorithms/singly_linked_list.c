#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void insfront(){

    struct node *temp = (struct node*)malloc(sizeof(struct node));

    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    temp->data = n;

    if(front==NULL)
    {
        front = temp;
        rear = temp;
        temp->next = NULL;
    }

    else
    {
        temp->next = front;
        front = temp;
    }
}

void insrear(){
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);

    temp->data =n;
    temp->next = NULL;

    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }

    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void delfront()
{
    if (front==NULL)
    {
        printf("\nSLL is Empty");
    }

    else
    {
        struct node *temp;
        temp = front;
        front = front->next;
        printf("\nDeleted Element is %d", temp->data);
        free(temp);
    }
}

void delrear()
{
    if (front==NULL)
    {
        printf("\nSLL is Empty");
    }

    else if (front -> next == NULL)
    {   
        printf("\nDeleted Element is %d", front->data);
        front = NULL;
        free(front);
    }

    else
    {
        struct node *prev, *count;
        count = front;
        while (count->next != NULL)
        {
            prev = count;
            count = count -> next;
        }
        printf("\nDeleted Element is %d", count->data);
        free(count);
        rear = prev;
        prev->next=NULL;

    }
}


void display()
{
    if (front == NULL)
    {
        printf("\nSLL is Empty");
    }

    else
    {
        struct node *temp;
        temp = front;
        printf("\nElements in SLL are:\n");
        while (temp != rear)
        {
            printf("\n%d",temp->data);
            temp= temp -> next;
        }
        printf("\n%d", temp->data);
            
    }
        

}


int main()
{
 
   int choice;
   char ch; 
   do 
    { 
       printf("\nSLL Menu : "); 
       printf("\n1.Insert Front"); 
       printf("\n2.Insert Rear"); 
       printf("\n3.Delete Front"); 
       printf("\n4.Delete Rear"); 
       printf("\n5.Display"); 

       printf("\n\nEnter your choice : "); 
       scanf("%d",&choice); 

       switch (choice) 
       { 
         case 1: insfront(); 
                 break; 

         case 2: insrear(); 
                break; 

        case 3: delfront(); 
                 break; 

        case 4: delrear(); 
                break; 
         
        case 5: display(); 
                break; 
        
        case 6: break;

        default: printf("\nInvalid Choice\n"); 
                break; 
       } 

    } while(choice!=6); 

  return 0;
}
