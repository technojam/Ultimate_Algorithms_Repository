// Kadane’s Algorithm
// Maximum Sub-Array Sum

#include <bits/stdc++.h>
using namespace std;

int maxSubSum(int a[], int n)
{
    int global = a[0];
    int current = a[0];
    for (int i = 1; i < n; i++)
    {
        current = max(a[i], current+a[i]);
        global = max(global, current);

    }
    return global;
}

int main()
{
    int a[] =  {-1, 7, 5, -3, 6, 1, -8, 3, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max = maxSubSum(a, n);
    cout << "Maximum Sub-Array Sum: " << max;
    return 0;
}
