#include <bits/stdc++.h>
using namespace std;

void kadane(int size,int arr)
{
    int max_so_far      = INT_MIN;
    int max_ending_here = 0;
    int max_element     = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max(max_ending_here + arr[i], 0);
        max_so_far      = max(max_ending_here, max_so_far);
        max_element     = max(max_element, arr[i]);
    }

    if (max_so_far == 0)
      max_so_far = max_element;

    cout << max_so_far;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    kadane(n , a);
    return 0;
}
