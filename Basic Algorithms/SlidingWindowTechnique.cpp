/*To find the maximum subarray sum of size k in an array of size n 
using the sliding window technique.
*/
/*
Sliding window technique can be used to optimise an algorithm.
Many problems which re solved in O(n^2)time can be solved in O(n) time
 using this technique.
*/
#include <bits/stdc++.h> 
using namespace std;  
int maxSum(int a[], int n, int k) 
{ 
    // n must be greater 
    if (n < k) { 
        cout << "Invalid"; 
        return -1; 
    } 
    // Compute sum of first window of size k 
    int max_sum = 0; 
    for (int i = 0; i < k; i++) 
        max_sum += a[i]; 
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of 
    // current window. 
    int window_sum = max_sum; 
    for (int i = k; i < n; i++) { 
        window_sum += a[i] - a[i - k]; 
        max_sum = max(max_sum, window_sum); 
    }   
    return max_sum; 
} 
int main() 
{ 
    int n,i;
    cout<<"Enter no. of elements:";
    cin>>n;
    int a[n];
    cout<<"Elements:";
    for(i=0;i<n;i++)
        cin>>a[i];
    int k;
    cout<<"Subarray size:\n";
    cin>>k;
    cout <<"Maximum sum is:"<< maxSum(a,n,k); 
    return 0; 
} 