#include<stdio.h>
struct Array
{
    int A[10];
    int length;
    int size;
};

void Display(struct Array arr)
{
    printf("\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int isSorted(struct Array *arr)
{
    for(int i=0;i<arr->length-1;i++)
    {
        if(arr->A[i]>arr->A[i+1]) return 0;
    }
    return 1;
}

int main()
{
    struct Array arr = {{2,3,1,5,6},5,10};
    Display(arr);
    if(isSorted(&arr)==1)
    {
        printf("\nSorted\n");
    }
    else
    {
        printf("\nUnsorted\n");
    }
}

