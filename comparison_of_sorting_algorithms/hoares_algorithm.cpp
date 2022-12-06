#include "header.h"

void sort_(int left, int right, int* arr, size_t& count)
{
	int i = left;
	int j = right;
	int support_element = arr[(i + j + 1) / 2];
	do {
		while (arr[i] < support_element) i++;
		while (arr[j] > support_element) j--;
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			count++;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		sort_(left, j, arr, count);
	if (i < right)
		sort_(i, right, arr, count);
}

void hoare_sort(int size, int* array, size_t& count)
{
	sort_(0, size - 1, array, count);
}

