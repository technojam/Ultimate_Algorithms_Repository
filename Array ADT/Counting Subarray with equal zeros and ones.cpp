#include <bits/stdc++.h>
using namespace std;
int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    map<int, int> mp;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
        sum += arr[i];
        if (sum == 0)
            count++;
        if (mp[sum])
            count += mp[sum];
        if (mp[sum] == 0)
            mp[sum] = 1;
        else
            mp[sum]++;
    }
    return count;
}
int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "count=" << countSubarrWithEqualZeroAndOne(arr, n);
}
