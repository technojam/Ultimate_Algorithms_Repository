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
            max = arr->A[i];
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
            min = arr->A[i];
        }
    }
    return min;
}

void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void MissingUnsorted(struct Array *arr)
{
    int h = Max(arr);
    int l = Min(arr);
    int *H=(int *)malloc((h+1)*sizeof(int));
    for(int i=0;i<h+1;i++)
    {
        H[i]=0;
    }
    for(int i=0;i<arr->length;i++)
    {
        H[arr->A[i]]++;
    }
    for(int i=l;i<h;i++)
    {
        if(H[i]==0) printf("%d ",i);
    }
    free(H);
}

int main()
{
    struct Array arr={{15,6,17,9,10,12,16,11},8,8};
    MissingUnsorted(&arr);
}
