#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL, *prev = NULL;

void push(){
    struct node *temp = malloc(sizeof(struct node));

    int n;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    temp->data = n;
    
    if (top == NULL)
    {
        temp->next = NULL;
        top=temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }

}

void pop(){

    if (top==NULL)
    {
        printf("\nStack is Empty");
    }
    else
    {
        prev=top;
        prev = prev->next;
        printf("The popped element is %d",top->data);
        free(top);
        top = prev;

    }
}

void display(){

    if (top==NULL)
    {
        printf("\nStack is Empty");
    }    
    else
    {
        prev = top;
        while (prev != NULL)
        {
            printf("\n%d", prev->data);
            prev=prev->next;
        }
        
    }

}

void peek(){

    if (top==NULL)
    {
        printf("\nStack is Empty");
    }  
    else
    {
        printf("The element at the TOP is %d",top->data);
    }
    

}

int main()
{
 
   int choice;
   char ch; 
   do 
    { 
       printf("\nQueue Menu : "); 
       printf("\n1.Push"); 
       printf("\n2.Pop"); 
       printf("\n3.Peek"); 
       printf("\n4.Display");
       printf("\n5.Exit");

       printf("\n\nEnter your choice : "); 
       scanf("%d",&choice); 

       switch (choice) 
       { 
         case 1: push(); 
                 break; 

         case 2: pop(); 
                break; 

        case 3: peek(); 
                 break; 

        case 4: display();
                break;
        
        case 5: printf("GoodBye");  
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
