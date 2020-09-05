#include<stdio.h>

struct Array
{
    int A[20];
    int length;
    int size;
};

void Count_Duplicates(struct Array *arr)
{
    int j;
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==arr->A[i+1])
        {
            j=i+1;
            while(arr->A[j]==arr->A[i])
            {
                j++;
            }
            printf("%d is duplicated %d times\n",arr->A[i],j-i);
            i=j-1;
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
    struct Array arr={{2,3,4,4,6,8,8,8,9,9,10},11,20};
    Display(arr);
    Count_Duplicates(&arr);
}
