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

struct Array * IntersectionUnsorted(struct Array* arr1,struct Array* arr2)
{
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int k=0;
    bool found = false;
    for(int i=0;i<arr1->length;i++)
    {
        for(int j=0;j<arr2->length;j++)
        {
            found = false;
            if(arr2->A[j]==arr1->A[i])
            {
                found = true;
                break;
            }
        }
        if(found == true)
        {
            arr3->A[k++]=arr1->A[i];
        }
    }
    arr3->length=k;
    arr3->size=20;
    return arr3;
}

int main()
{
    struct Array arr1 = {{2,6,15,10,25,0},6,20};
    struct Array arr2 = {{3,6,15,1,20},5,20};
    Display(arr1);
    Display(arr2);
    struct Array *arr3;
    arr3=IntersectionUnsorted(&arr1,&arr2);
    Display(*arr3);
}
