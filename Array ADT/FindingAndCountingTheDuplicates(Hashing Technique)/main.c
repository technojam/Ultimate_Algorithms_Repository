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

int Min(struct Array *arr)
{
    int min=arr->A[0];
    for(int i=1;i<arr->length;i++)
    {
        if(arr->A[i]<min)
        {
            min=arr->A[i];
        }
    }
    return min;
}

void Count_Duplicates(struct Array *arr)
{
    int l=Min(arr);
    int h=Max(arr);
    int *H=(int *)malloc((h+1)*sizeof(int));
    for(int i=0;i<h+1;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<arr->length;i++)
    {
        H[arr->A[i]]++;
    }
    for(int i=l;i<h+1;i++)
    {
        if(H[i]>1)
        {
            printf("%d is duplicated %d times\n",i,H[i]);
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
    struct Array arr={{2,3,4,4,6,8,8,8,9,9,10,10},12,20};
    Display(arr);
    Count_Duplicates(&arr);
}
