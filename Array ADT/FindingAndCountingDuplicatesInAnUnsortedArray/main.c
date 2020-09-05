#include<stdio.h>

struct Array
{
    int A[20];
    int length;
    int size;
};

void Count_Duplicates(struct Array arr)
{
    int count;
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]!=-1)
        {
            count=1;
            for(int j=i+1;j<arr.length;j++)
            {
                if(arr.A[j]==arr.A[i])
                {
                    count++;
                    arr.A[j]=-1;
                }
                
            }
            if(count>1)
                printf("%d is duplicated %d times\n",arr.A[i],count);
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
    Count_Duplicates(arr);
}
