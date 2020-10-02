/* Bubble sort work like that it will compare itself with it's imidiate 
right if it is greater then it will swap otherwise move and after every pass 
it will put the greatest element in the last 
time complexity O(n^2)
*/

#include <bits/stdc++.h> 
using namespace std; 
  
  //Swap function
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  

//sort function
void bubbleSort(int arr[], int n)  
{  
   for (int i = 0; i < n-1; i++){    
    for (int j = 0; j < n-i-1; j++){  
        if (arr[j] > arr[j+1]) { 
            swap(&arr[j], &arr[j+1]); }
    }
  }
}  
  
int main()  
{  
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];    
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
     for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    return 0;  
}  
  