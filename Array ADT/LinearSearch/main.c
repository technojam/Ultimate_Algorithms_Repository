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


int LinearSearch(struct Array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
    Display (arr);
    printf("Element searched at index %d\n",LinearSearch(&arr,4));
}
