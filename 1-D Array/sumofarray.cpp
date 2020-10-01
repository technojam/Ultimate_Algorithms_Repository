#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int i, n, sum=0;

    
    cout<<"Enter array size: ";
    scanf("%d", &n);

   
    cout<<"Enter elements in the array: ";
    for(i=0; i<n; i++)
    {
       cin>>arr[i];
    }

   
    for(i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }


    cout<<"Sum of all elements of array = "<<sum;

    return 0;
}
