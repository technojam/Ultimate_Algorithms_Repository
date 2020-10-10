//inspace algorithm
//divide and conquer
//N log N on avg case and N^2 worst case
#include<iostream>
using namespace std;

int partition(int *a, int s, int e) {
	int i = s - 1;
	int j = s;
	int pivot = a[e];
	for (; j <= e - 1;) {
		if (a[j] <= pivot) {
			i = i + 1;
			swap(a[i], a[j]);
		}
		j = j + 1;
	}
	swap(a[i + 1], a[e]);
	return i + 1;

}
void quick_sort(int *arr, int s, int e) {
	if (s >= e) {
		return;
	}
//recursive case
	int p = partition(arr, s, e);
//left part
	quick_sort(arr, s, p - 1);
//right part
	quick_sort(arr, p + 1, e);
}

int main() {
	int arr[] = {2, 3, 8, 6, 1, 5, 4};
	quick_sort(arr, 0, 6);

	for (int i = 0; i <= 6; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
