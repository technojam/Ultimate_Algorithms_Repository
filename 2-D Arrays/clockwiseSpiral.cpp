#include <iostream>
using namespace std;

#define Row 4
#define Col 4


void print(int arr[Row][Col], int i, int j, int m, int n)
{
    if (i >= m or j >= n)
        return;


    for (int p = i; p < n; p++)
        cout << arr[i][p] << " ";


    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";


    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";


    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";

    print(arr, i + 1, j + 1, m - 1, n - 1);
}


int main()
{

    int a[Row][Col] = { { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    // Function Call
    print(a, 0, 0, Row, Col);
    return 0;
}