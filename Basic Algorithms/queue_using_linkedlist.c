#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(){
    
    struct node *temp = malloc(sizeof(struct node));

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

    void dequeue()
    {
        if (front==NULL)
        {
            printf("\nQueue is Empty");
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

    void display()
    {
        if (front == NULL)
        {
            printf("\nQueue is Empty");
        }

        else
        {
            struct node *temp;
            temp = front;
            printf("\nElements in Queue are:\n");
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
       printf("\nQueue Menu : "); 
       printf("\n1.Enqueue"); 
       printf("\n2.Dequeue"); 
       printf("\n3.Display"); 
       printf("\n4.Exit"); 
       printf("\n\nEnter your choice : "); 
       scanf("%d",&choice); 

       switch (choice) 
       { 
         case 1: enqueue(); 
                 break; 

         case 2: dequeue(); 
                break; 
  
         case 3: display(); 
                break; 

         case 4:printf("GoodBye");  
                return 0; 
                break; 

         default: printf("\nInvalid Choice\n"); 
                 break; 
       } 

       printf("\nWant to perform more (Y/y):"); 
       scanf(" %c", &ch); 
    
    } while(ch == 'Y' || ch == 'y'); 

  return 0;
}
    
    





