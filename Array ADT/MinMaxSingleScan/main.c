#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int length;
    int size;
};
void MinMax(struct Array *arr)
{
    int min=arr->A[0];
    int max=arr->A[0];
    for(int i=1;i<arr->length;i++)
    {
        if(arr->A[i]<min)
        {
            min=arr->A[i];
        }
        else if(arr->A[i]>max)
        {
            max=arr->A[i];
        }
    }
    printf("Min is %d\nMax is %d\n",min,max);
}

void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array arr={{5,8,3,9,6,2,10,7,-1,4},10,20};
    Display(arr);
    MinMax(&arr);
}
