#include<stdio.h>
#include<stdlib.h>
struct Array                     //structure Array Definition
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)          // Display() displays the elements in the array
{
    printf("\nElements are:-\n\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array arr;
    int n;
    printf("Enter the size of the array ");
    scanf("%d",&arr.size);
    
    arr.A= (int *)malloc(arr.size*sizeof(int));    //Dynamic Memory allocation of array "arr.A"
    arr.length=0;
    
    printf("Enter the number of numbers ");
    scanf("%d",&n);
    
    if(n>arr.size)
    {
        printf("The number of elements cannot be more than the Array size");
    }
    else
    {
        printf("Enter all the elements\n");     //Dynamic Initialization of array
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr.A[i]);
        }
        arr.length=n;
        
        Display (arr);
    }
}
