#include<stdio.h>
#include "../../utilities.h"

int partition (int A[], int start, int end) {
	int i = start - 1;
	int j = start;
	int pivot = A[end];

	for (; j < end; j++) {
		if (A[j] <= pivot) {
			i++;
			int tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}

	int tmp = A[i+1];
	A[i+1] = A[end];
	A[end] = tmp;

	return i+1;
}

void quicksort (int A[], int start, int end) {
	if (start < end) {
		int x = partition(A, start, end);
		quicksort(A, start, x-1);
		quicksort(A, x+1, end);
	}
}

int main () {
	int A[10] = {4,3,5,2,3,8,9,12,11,1};
	quicksort(A, 0, 9);

	printIntArray(A, 10, "");
}
