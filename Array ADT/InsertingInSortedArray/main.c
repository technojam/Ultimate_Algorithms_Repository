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

void Insert(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        int i=arr->length-1;
        while(i>=0 && arr->A[i]>x)
        {
            arr->A[i+1]=arr->A[i];
            i--;
        }
        arr->A[i+1]=x;
        arr->length++;
    }
}

int main()
{
    struct Array arr = {{2,4,10,15,18},5,10};
    Display(arr);
    Insert(&arr,1);
    Display(arr);
}



