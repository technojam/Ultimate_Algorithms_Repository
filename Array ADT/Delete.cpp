#include<stdio.h>
#include<stdlib.h>
struct Array                      //structure Array Definition
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)          // Display() displays the elements in the array
{
    printf("\nElements are:-\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int Delete(struct Array *arr,int index)                 //Delete() function will delete the element at the given index
{
    if(index>=0 && index<arr->length)
    {
        int x = arr->A[index];
        for(int i=index;i<arr->length;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}


int main()
{
    struct Array arr={{2,3,4,5,6},20,5};
    Display (arr);
    
    printf("Deleted element is:- %d ",Delete(&arr,3));
    Display(arr);
    
}


