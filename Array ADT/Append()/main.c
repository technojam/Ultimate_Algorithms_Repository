#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements are:-\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr,int element)
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
    Append(&arr,10);
    Display (arr);
}

