// This algorithm rotates an an array inplace.
// Time complexity :- O(n)
//Space Complexity :- O(1)
// Here in this implementation I will left rotate the array a of size n by k elements

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void RotateLeft(int a[], int k, int n)
{
	int d=-1,i,temp,j;
	for(int i=0;i<gcd(n,k);i++)
    {
        j=i;
        temp=a[i];
        while(1)
        {
            d=(j+k)%n;
            if(d==i)
                break;
            a[j]=a[d];
            j=d;
        }
        a[j]=temp;
    }
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 11, 22, 33, 44, 54, 66, 77 };
	int n = sizeof(arr) / sizeof(arr[0]);
	RotateLeft(arr, 3, n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
	return 0;
}
