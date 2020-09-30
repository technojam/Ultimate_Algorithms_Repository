#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Array                      //structure Array Definition
{
    int A[20];
    int length;
    int size;
};

void Display(struct Array arr)          // Display() displays the elements in the array
{
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

struct Array * DifferenceUnsorted(struct Array *arr1, struct Array *arr2)       //DifferenceUnsorted() gives the difference between unsorted arrays arr1 and arr2 (arr1 - arr2)
{
    int k=0;
    bool found = false;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    for(int i=0;i<arr1->length;i++)
    {
        found = false;
        for(int j=0;j<arr2->length;j++)
        {
            if(arr1->A[i]==arr2->A[j])
            {
                found = true;
                break;
            }
        }
        if(found==false)
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
    struct Array arr2 = {{3,6,15,1,0},5,20};
    printf("arr1 : ");
    Display(arr1);
    printf("arr2 : ");
    Display(arr2);
    struct Array *arr3;
    arr3=DifferenceUnsorted(&arr1,&arr2);                           //calling by reference
    printf("difference between arr1 and arr2 (arr1 - arr2) : ");
    Display(*arr3);
}
