 
#include <bits/stdc++.h> 
using namespace std; 


int optimalStrategyOfGame( 
	int* arr, int n) 
{ 
	
	int table[n][n]; 

	for (int gap = 0; gap < n; ++gap) { 
		for (int i = 0, j = gap; j < n; ++i, ++j) { 
			
			int x = ((i + 2) <= j) 
						? table[i + 2][j] 
						: 0; 
			int y = ((i + 1) <= (j - 1)) 
						? table[i + 1][j - 1] 
						: 0; 
			int z = (i <= (j - 2)) 
						? table[i][j - 2] 
						: 0; 

			table[i][j] = max( 
				arr[i] + min(x, y), 
				arr[j] + min(y, z)); 
		} 
	} 

	return table[0][n - 1]; 
} 

// Driver program to test above function 
int main() 
{ 
	int arr1[] = { 8, 15, 3, 7 }; 
	int n = sizeof(arr1) / sizeof(arr1[0]); 
	printf("%d\n", 
		optimalStrategyOfGame(arr1, n)); 

	int arr2[] = { 2, 2, 2, 2 }; 
	n = sizeof(arr2) / sizeof(arr2[0]); 
	printf("%d\n", 
		optimalStrategyOfGame(arr2, n)); 

	int arr3[] = { 20, 30, 2, 2, 2, 10 }; 
	n = sizeof(arr3) / sizeof(arr3[0]); 
	printf("%d\n", 
		optimalStrategyOfGame(arr3, n)); 

	return 0; 
} 
