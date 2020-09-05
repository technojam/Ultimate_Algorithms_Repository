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

int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr,int index, int x)
{
     if(index>=0 && index<arr->length)
     {
         arr->A[index]=x;
     }
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int Total=0;
    for(int i=0;i<arr.length;i++)
        Total=Total+arr.A[i];
    return Total;
}

float Avg(struct Array arr)
{
    float sum = (float)Sum(arr);
    return (float)sum/arr.length;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},5,10};
    Display(arr);
    printf("\n%d",Get(arr,2));
    Set(&arr,2,800);
    Display(arr);
    printf("\n%d",Max(arr));
    printf("\n%d",Min(arr));
    printf("\n%d",Sum(arr));
    printf("\n%lf\n",Avg(arr));
}
