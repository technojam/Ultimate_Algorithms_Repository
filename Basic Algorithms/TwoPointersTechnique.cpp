/* 
Two pointer technique based solution to find 
if there is a pair in A[0..N-1] with a given sum. 
 */
/*
Two pointers is an easy and effective technique which is 
typically used for searching pairs in a sorted array.
*/
#include<bits/stdc++.h>
using namespace std;
bool isPairSum(int a[],int n,int x) 
{ 
    int i=0;  
    int j=n-1;
    //i represents 1st pointer and j represents 2nd pointer  
    while (i < j) {   
        // If we find a pair 
        if (a[i]+a[j]==x) 
            return true; 
        else if (a[i]+a[j]<x)     // If sum of elements at current 
           i++;                   // pointers is less, we move towards 
                                 // higher values by doing i++ 

        else                   // If sum of elements at current 
         j--;                     // pointers is more, we move towards 
                                // lower values by doing j-- 
    } 
    return false; 
} 
int main(){
    int n,i;
    cout<<"Enter no. of elements:";
    cin>>n;
    int a[n];
    cout<<"Elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    int sum;
    cout<<"Sum to find:\n";
    cin>>sum;
    if(isPairSum(a,n,sum))
        cout<<"Yes,a pair with sum "<<sum<<" exists\n";
    else
        cout<<"No,a pair with sum "<<sum<<" doesn't exist\n";
    return 0; 
}
