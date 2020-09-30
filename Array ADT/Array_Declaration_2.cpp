#include<stdio.h>
#include<stdlib.h>
struct Array                      //structure Array Definition
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)          // Display() displays the elements in the array
{
    printf("\nElements are:-\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array arr={{2,3,4,5,6},20,5};           //Static Initialization of Array "arr"
    Display (arr);
}
