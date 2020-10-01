// C++ code to solve couting sort (A sorting algorithm)
// It works fine when you have less range of number.


/* Algorithm */

// step-1 : Find the maximum value in the array;
// step-2 : Create an array (count_array) of that size and put 0 in all the index;
// step-3 : Store the frequencies of each distinct element of array by,
		 // mapping its value as the index of count_array;


// Further steps are included below


#include <bits/stdc++.h>  // Header file which included 30++ header files in it

using namespace std;

int main()
{
	int size;       	// Declaring a var
	cin>>size;      	// Taking input(size of the array)
	int array[size];   // Decalaring an array with size(given by user);

	for ( int i = 0; i < size ; i++)  // Taking elements of an array from the user
	cin>>array[i];

	int max = *max_element(array, array + size); // This will return max value in an array;

	int count_array[max];

	memset(count_array, 0, sizeof(count_array));  // This function fills 0 in whole array;

//	for ( int i = 0; i < max ; i++)
//	cout<<count_array[i]<<" ";


	for(int i = 0; i < size ; i++)
    count_array[ array [i] ]++;

    int sortarr[size];

    int j = 0;

    for(int i = 0; i <= max; i++)
	{
        int temp = count_array[i];

        // count_array stores which element occurs how many times,
        // Add i in sortarr[] according to the number of times i occured in array[]
        // which will let sortarr[] store the values in increasing order;

        while(temp--)
		{
            //cout << count_array[i] <<" ";
            sortarr[j] = i;
            j++;
        }
    }

    cout<<"Sorted array using counting sort\n";

    for ( int i = 0; i < size ; i++)
    cout<<sortarr[i]<<"  ";

	return 0;
}


// Note : Don't use this sorting algorithm if your data is significantly
// greater than the number of objects to be sorted,
// Try to use merge sort or quick sort or sort() function provided by C++;

// Time complexity : O(size + max)

// Space complexity : O(size + max)



// Contributed By @yugandhar_surya //
