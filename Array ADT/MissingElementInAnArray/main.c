#include<stdio.h>

struct Array
{
    int A[20];
    int length;
    int size;
};

void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void Missing(struct Array *arr)
{
    int diff=arr->A[0]-0;
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]-i!=diff)
        {
            while(diff<arr->A[i]-i)
            {
                printf("%d ",diff+i);
                diff++;
            }
        }
    }
}

int main()
{
    struct Array arr={{5,6,7,9,10,12,16,20},8,8};
    Missing(&arr);
}
