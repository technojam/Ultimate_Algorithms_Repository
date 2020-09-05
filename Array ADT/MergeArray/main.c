#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[20];
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

struct Array * Merge (struct Array *arr1,struct Array *arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i++];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j++];
    arr3->size=arr3->length=arr1->length+arr2->length;
    return arr3;
}

int main()
{
    struct Array arr1 = {{2,6,10,15,25},5,20};
    struct Array arr2 = {{3,4,7,18,20,21},6,20};
    struct Array *arr3;
    Display(arr1);
    Display(arr2);
    arr3 = Merge(&arr1,&arr2);
    Display(*arr3);
    printf("\n");
}



