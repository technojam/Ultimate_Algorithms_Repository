#include<stdio.h>
struct Array                      //structure Array Definition
{
    int A[10];
    int length;
    int size;
};

void Display(struct Array arr)          // Display() displays the elements in the array
{
    printf("\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int Get(struct Array arr,int index)     // Get() returns the element at Index "index"
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr,int index, int x)          // Set() Sets the element at Index "index"
{
     if(index>=0 && index<arr->length)
     {
         arr->A[index]=x;
     }
}

int Max(struct Array arr)                    // Max() returns the largest number in the array
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)                     //Min() returns the smallest number in the array
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)                      //Sum() returns the sum of all the numbers in the array
{
    int Total=0;
    for(int i=0;i<arr.length;i++)
        Total=Total+arr.A[i];
    return Total;
}

float Avg(struct Array arr)                    //Avg() returns the average of all the numbers in the array
{
    float sum = (float)Sum(arr);
    return (float)sum/arr.length;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},5,10};         //Static Initialization of Array "arr"
    Display(arr);
    printf("\n%d",Get(arr,2));
    Set(&arr,2,800);
    Display(arr);
    printf("\n%d",Max(arr));
    printf("\n%d",Min(arr));
    printf("\n%d",Sum(arr));
    printf("\n%lf\n",Avg(arr));
}
