#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
            a[j++] = a[i];
    }
    a[j++] = a[n - 1];
    n = j;
    cout << "Your sorted elements are: ";
    for (int i = 0; i < n; i++)
        cout << a[i];
    return 0;
}