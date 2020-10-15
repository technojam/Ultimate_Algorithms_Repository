/**

//c++ code to count max sub array

#include <stdio.h>
#include <limits.h>


int max(int a, int b) { return (a > b)? a : b; }


int max(int a, int b, int c) { return max(max(a, b), c); }


int maxCrossingSum(int arr[], int l, int m, int h)
{

    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }


    sum = 0;
    int right_sum = INT_MIN;
    int i = m+1;
    while(i<=h)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
        i++;
    }


    return max(left_sum + right_sum, left_sum, right_sum);
}


int maxSubArraySum(int arr[], int l, int h)
{

   if (l == h)
     return arr[l];


   int m = (l + h)/2;


   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}


int main()
{
     int n;
     printf("Enter No of elements : ");
     scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
    }

   int max_sum = maxSubArraySum(arr, 0, n-1);
   printf("Maximum subarray sum is %d", max_sum);
   getchar();
   return 0;
}
**/

#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

int Max_Subarray_Sum(int arr[],int n)	
{
	if(n==1)
	{
		return arr[0];
	}
	int m = n/2;
	int left_MSS = Max_Subarray_Sum(arr,m);
	int right_MSS = Max_Subarray_Sum(arr+m,n-m);
	int leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
	for(int i=m;i < n; i++)
	{
		sum += arr[i];
		rightsum = max(rightsum,sum);
	}
	sum = 0;
	for(int i= (m-1);i >= 0; i--)
	{
		sum += arr[i];
		leftsum = max(leftsum,sum);
	}
	int ans = max(left_MSS,right_MSS);
	return max(ans,leftsum+rightsum);
}


int main(int argc, char const *argv[])
{

    int n;
     printf("Enter No of elements : ");
     scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
    }
//	int arr[] = {3,-2,5,-1};
	cout<<Max_Subarray_Sum(arr,n)<<"\n";
	return 0;
}
