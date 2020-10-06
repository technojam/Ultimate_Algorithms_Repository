#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int i,j, t;
    long long int arr[n];

    //Input from user
    for (i = 0; i < n; i++)
        cin >> arr[i];

    //Selection sort for sorting the element of given array
    for (i = 0; i < n; i++)
    {
        //Comparision for sorting the element of given array.
        for ( j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                {
                     int u = arr[i];
                     arr[i] = arr[j];
                     arr[j] = u;
                }
        }

    }
  //display sorted array
    for (i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}