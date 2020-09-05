#include<stdio.h>

struct Array
{
    int A[20];
    int length;
    int size;
};

void Duplicates(struct Array *arr)
{
    int last_duplicate=0;
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==arr->A[i+1] && arr->A[i]!=last_duplicate)
        {
            printf("%d ",arr->A[i]);
            last_duplicate=arr->A[i];
        }
    }
    printf("\n");
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
    struct Array arr={{2,3,4,4,6,8,8,8,9,9,10},11,20};
    Display(arr);
    Duplicates(&arr);
}
