#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int length;
    int size;
};
void FindPair(struct Array *arr,int k)
{
    int i=0,j=arr->length-1;
    while(i<j)
    {
        if(arr->A[i]+arr->A[j]==k)
        {
            printf("%d+%d=%d\n",arr->A[i],arr->A[j],k);
            i++;
            j--;
        }
        else if(arr->A[i]+arr->A[j]<k)
        {
            i++;
        }
        else
        {
            j--;
        }
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
    struct Array arr={{1,3,4,5,6,8,9,10,12,14},10,20};
    Display(arr);
    FindPair(&arr,11);
}
