#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int length;
    int size;
};

int Max(struct Array *arr)
{
    int max=arr->A[0];
    for(int i=1;i<arr->length;i++)
    {
        if(arr->A[i]>max)
        {
            max=arr->A[i];
        }
    }
    return max;
}


void FindPair(struct Array *arr,int k)
{
    int h=Max(arr);
    int *H=(int *)malloc((h+1)*sizeof(int));
    for(int i=0;i<h+1;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<arr->length;i++)
    {
        if(H[k-arr->A[i]]!=0)
        {
            printf("%d+%d=%d\n",arr->A[i],k-arr->A[i],k);
        }
        H[arr->A[i]]++;
    }
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
    struct Array arr={{6,3,8,10,16,7,5,2,9,14},10,20};
    Display(arr);
    FindPair(&arr,11);
}
