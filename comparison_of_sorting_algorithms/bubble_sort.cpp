#include "header.h"

void bubleSort(int* arr, size_t& bubleCounter, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++) {
		for (size_t j = i + 1; j < arrSize ; j++) 
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
				bubleCounter++;
			}
		}
}