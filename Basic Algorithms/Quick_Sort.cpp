#include <iostream> 
using namespace std;
// swap value function to exchange array value locations.
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
// function to create partition keeping a value as pivot to divide the array
int part (int arr[], int low, int high)
{
    int pivot = arr[high]; // assigning pivot to the ending index
    int i = (low - 1);  //smaller element index
    for (int j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] <= pivot) 
        { 
            i++;    //index increament of smmaller element
            swap(&arr[i], &arr[j]); //swap if value less than or equal to pivot value
        } 
    } 
    swap(&arr[i + 1], &arr[high]); //swapping using pass by location
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) //quick sort function
{ 
    if (low < high) 
    {   //pi=partitioning index
        int pi = part(arr, low, high);  // part function call
        quickSort(arr, low, pi - 1); //recursion 
        quickSort(arr, pi + 1, high); 
    } 
} 
