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

int BinarySearch(struct Array arr,int l,int h,int key)
{
   while(l<=h)
   {
       int mid=(l+h)/2;
       if(key==arr.A[mid])
       {
           return mid;
       }
       else if(key<arr.A[mid])
       {
           h=mid-1;
       }
       else
       {
           l=mid+1;
       }
   }
    
    return -1;
}

int main()
{
    struct Array arr = {{2,3,4,5,6},10,5};
    Display(arr,arr.length);
    printf("%d\n",BinarySearch(arr,0,arr.length-1,3));
}
