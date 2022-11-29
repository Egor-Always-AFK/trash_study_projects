#include "header.h"

void quicksort(int *arr, int f, int l)
{
	// quickSortOperations = 0;
	int first = f;
	int last = l;
	int mid = arr[(l + f)/ 2];
	while (arr[first] < arr[mid])
		first++;
	while (arr[last] > arr[mid])
		last--;

	if (first <= last)
	{
		int tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
		first++;
		last--;
	}

	while (first < last)
	{
		if (f < last)
			quicksort(arr, f, last);
		if (first < l)
			quicksort(arr, first, l);
		quickSortOperations++;
	}
}