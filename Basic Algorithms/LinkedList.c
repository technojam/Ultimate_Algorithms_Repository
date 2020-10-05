#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_ll(struct node *);
void display_ll(struct node *);
struct node *insert_beginning(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after_num(struct node *);
struct node *insert_before_num(struct node *);
struct node *delete_beginning(struct node *);
struct node *delete_end(struct node *);

int main(){
    int choice;

    while(1){
        printf("\n\n--OPTIONS AVAILABLE--\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert after a Number\n");
        printf("6. Insert Before a Number\n");
        printf("7. Delete First node\n");
        printf("8. Delete Last Node\n");
        printf("Enter -1 to Exit.\n");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case -1: printf("\nThanks for using my program.");
                exit(0);
            case 1:
                if(start == NULL)
                {
                    start = create_ll(start);
                    printf("\nLinked List Created.");
                }
                else{
                    printf("\nLinked List Already Created.");
                }
                break;
            case 2: printf("\nThe Linked List till now:\t");
                display_ll(start);
                printf("\n");
                break;
            case 3: start = insert_beginning(start);
                printf("\nNode Inserted.");
                break;
            case 4: start = insert_end(start);
                printf("\nNode Inserted.");
                break;
            case 5: start = insert_after_num(start);
                printf("\nNode Inserted.");
                break;
            case 6: start = insert_before_num(start);
                printf("\nNode Inserted.");
                break;
            case 7: if(start==NULL)
                        printf("UNDZERZFLOW");
                    else
                    {
                        start = delete_beginning(start);
                        printf("\nNode Deleted");
                    }
                break;
            case 8: if(start==NULL)
                        printf("UNDZERZFLOW");
                    else
                    {
                        start = delete_end(start);
                        printf("\nNode Deleted");
                    }
                break;
            default: printf("\nWrong Choice");
        }
    }
}
struct node *create_ll(struct node *start){
    struct node *new_node;
    int num;
    printf("\nEnter value to be inserted: ");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    start = new_node;
}
void display_ll(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}
struct node *insert_beginning(struct node *start){
    struct node *new_node;
    int num;
    printf("\nEnter a value to insert in linked list or -1 to exit : ");
    scanf("%d",&num);
    while(num != -1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        new_node->next=start;
        start=new_node;
        printf("\nEnter a value to insert in linked list or -1 to exit: ");
        scanf("%d",&num);
    }
    return start;
}
struct node *insert_end(struct node *start){
    struct node *ptr, *new_node;
    int num;
    printf("Enter number to insert at the end or -1 to stop inserting: ");
    scanf("%d", &num);
    while(num!=-1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next = new_node;
        printf("Enter number to insert at the end or -1 to stop inserting: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *insert_after_num(struct node *start){
    struct node *ptr, *new_node;
    int num,val;
    printf("Enter number to insert at the end or -1 to stop inserting: ");
    scanf("%d", &num);
    while(num != -1){
        printf("Enter number after which %d to be inserted: ", num);
        scanf("%d", &val);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        new_node->next=NULL;
        ptr=start;
        while(ptr->data!=val)
            ptr=ptr->next;
        new_node->next=ptr->next;
        ptr->next=new_node;
        printf("Enter number to insert at the end or -1 to stop inserting: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *insert_before_num(struct node *start){
    struct node *ptr, *new_node;
    int num,val;
    printf("Enter number to inserted or -1 to stop inserting: ");
    scanf("%d", &num);
    while(num != -1){
        printf("Enter number before which %d to be inserted: ", num);
        scanf("%d", &val);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        new_node->next=NULL;
        ptr=start;
        if(start->data == val){
            new_node->next=start;
            start = new_node;
        }
        else{
            while(ptr->next != NULL){
                if(ptr->next->data == val){
                    new_node->next=ptr->next;
                    ptr->next=new_node;
                    break;
                }
                else
                    ptr=ptr->next;
            }
        }

        printf("Enter number to insert before a num or -1 to stop inserting: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *delete_beginning(struct node *start){
    struct node *ptr;
    ptr=start;
    start=ptr->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    preptr = start;
    ptr=preptr;
    while(ptr->next != NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}
