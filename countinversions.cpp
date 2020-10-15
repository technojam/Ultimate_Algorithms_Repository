//c++ code to count no of inversions
#include <bits/stdc++.h>

using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);

int merge(int arr[], int temp[], int left, int mid, int right);


int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {

        mid = (right + left) / 2;


        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);


        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}


int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}





int merge(int arr[], int temp[], int left,
        int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];


            inv_count = inv_count + (mid - i);
        }
    }


    while (i <= mid - 1)
        temp[k++] = arr[i++];


    while (j <= right)
        temp[k++] = arr[j++];


    i=left;
        while(i<=right)
        {
        arr[i] = temp[i];
        i++;
    }

    return inv_count;
}

// Driver code
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

   // int arr[] = { 1, 20, 6, 4, 5 };
    //int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}

