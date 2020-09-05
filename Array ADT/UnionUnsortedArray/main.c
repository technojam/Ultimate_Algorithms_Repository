#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
    printf("\n");
}
struct Array * UnionUnsorted(struct Array *arr1,struct Array *arr2)
{
    int k=0;
    bool found;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(int i=0;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    for(int j=0;j<arr2->length;j++)
    {
        found = false;
        for(int i=0;i<k;i++)
        {
            if(found==false)
            {
                if(arr2->A[j]==arr3->A[i])
                    found = true;
            }
            else
                break;
        }
        if(found==false)
            arr3->A[k++]=arr2->A[j];
    }
    
    arr3->length=k;
    arr3->size=20;
    return arr3;
    
}

int main()
{
    struct Array arr1 = {{2,6,10,15,25},5,10};
    struct Array arr2 = {{3,6,15,1,20},5,10};
    Display(arr1);
    Display(arr2);
    struct Array *arr3;
    arr3=UnionUnsorted(&arr1,&arr2);
    Display(*arr3);
}
