#include<stdio.h>
#include<stdlib.h>
struct Array                       //structure Array Definition
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)         // Display() displays the elements in the array
{
    printf("\nElements are:-\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr,int element)      // Append() appends an element at the end of the array
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length]=element;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{2,3,4,5,6},20,5};       
    Display (arr);
    Append(&arr,10);          // "&arr" is passed by reference 
    Display (arr);
}

