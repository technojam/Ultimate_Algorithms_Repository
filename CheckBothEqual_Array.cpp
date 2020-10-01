//Given two arrays A and B of equal size, the task is to find
//if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.

#include <bits/stdc++.h>
#include<algorithm>

using namespace std;
bool check(long long int arr[],long long brr[],long long int n)
{
    sort(arr,arr+n);
    sort(brr,brr+n);
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=brr[i])
        return false;
    }
    return true;
}
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    long long int  arr[n],brr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>brr[i];
	    }
	   if(check(arr,brr,n))
	   cout<<"1\n";
	   else
	   cout<<"0\n";
	}
	return 0;
}