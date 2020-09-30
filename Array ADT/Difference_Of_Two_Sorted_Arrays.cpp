#include<stdio.h>
#include<stdlib.h>

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

struct Array * DifferenceSorted(struct Array *arr1, struct Array *arr2)       //DifferenceSorted() gives the difference between sorted arrays arr1 and arr2 (arr1 - arr2)
{
    struct Array * arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr2->A[j]<arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    arr3->length=k;
    arr3->size=20;
    return arr3;
}

int main()
{
    struct Array arr1 = {{2,6,10,15,21,25},6,20};
    struct Array arr2 = {{3,6,15,18,20},5,20};
    printf("arr1 : ");
    Display(arr1);
    printf("arr2 : ");
    Display(arr2);
    struct Array *arr3;
    arr3=DifferenceSorted(&arr1,&arr2);                           //calling by reference
    printf("difference between arr1 and arr2 (arr1 - arr2) : ");
    Display(*arr3);
}
