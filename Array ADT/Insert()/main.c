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

void Insert(struct Array *arr,int index,int element)
{
    if(arr->length<arr->size && 0<=index && index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=element;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{2,3,4,5,6},20,5};
    Display (arr);
    Insert (&arr,9,10);
    Display (arr);
}


