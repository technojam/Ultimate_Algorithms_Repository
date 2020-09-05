#include<stdio.h>
struct Array
{
    int A[10];
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

void Separate(struct Array *arr)
{
    int i=0;
    int j=arr->length-1;
    int temp;
    while(i<j)
    {
        while(arr->A[i]<0) {i++;}
        while(arr->A[j]>=0) {j--;}
        if(i<j)
        {
            temp=arr->A[i];
            arr->A[i]=arr->A[j];
            arr->A[j]=temp;
        }
    }
}

int main()
{
    struct Array arr = {{2,1,0,-5,3,-6},6,10};
    Display(arr);
    Separate(&arr);
    Display(arr);
}



