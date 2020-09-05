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

void LeftRotate(struct Array *arr)
{
    int temp = arr->A[0];
    for(int i=1;i<arr->length;i++)
    {
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1]=temp;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},5,10};
    Display(arr);
    LeftRotate(&arr);
    Display(arr);
}


