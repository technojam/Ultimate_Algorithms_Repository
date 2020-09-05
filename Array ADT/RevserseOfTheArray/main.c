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

void Reverse(struct Array *arr)
{
    int temp;
    for(int i=0,j=arr->length-1;i<j;i++,j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
int main()
{
    struct Array arr = {{2,3,4,5,6},5,10};
    Display(arr);
    Reverse(&arr);
    Display(arr);
}

