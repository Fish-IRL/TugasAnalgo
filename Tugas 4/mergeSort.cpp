#include <iostream>
#include <time.h>

using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << A[i] << " ";
	cout << endl; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int min = 0;
	int max = 100;
	int arr[100000];
	for (int i = 0; i < 10000; i++) {
		arr[i] = rand()%(max-min + 1) + min;
	}
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	clock_t t1, t2;

	// cout << "Given array is : ";
	// printArray(anrr, arr_size); 
	
	t1 = clock();
	mergeSort(arr, 0, arr_size - 1); 
	t2 = clock();

	float diff ((float)t2 -(float)t1);

	// cout << "Sorted array is : ";
	// printArray(arr, arr_size); 
	cout << "Runtime : " << diff << " ms";
	return 0; 
} 
