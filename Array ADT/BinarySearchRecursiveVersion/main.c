#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr,int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

int BinarySearch(int A[],int l,int h,int key)
{
    int mid;
   while(l<=h)
   {
       mid=(l+h)/2;
       if(key==A[mid])
       {
           return mid;
       }
       else if(key<A[mid])
       {
           return BinarySearch(A,l,mid-1,key);
       }
       else
       {
           return BinarySearch(A,mid+1,h,key);
       }
   }
    
    return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};
    Display(arr,arr.length);
    printf("%d\n",BinarySearch(arr.A,0,arr.length-1,6));
}
