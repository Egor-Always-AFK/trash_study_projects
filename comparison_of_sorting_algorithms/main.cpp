// #include "header.h"
#include <iostream>
#include <iomanip>
#include <random>


int quickSortOperations;
// int quickSortOperations = 0;

int bubbleSort(int *arr)
{
    int ret = 0;
    for (std::size_t i = 0; i <= 1000; i++)
    {
        for (std::size_t j = i + 1; j <= 1000; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
                ret++;
            }
        }
    }
    return ret;
}

void quicksort(int *arr, int f, int l)
{
	// quickSortOperations = 0;
	int first = f;
	int last = l;
	int mid = arr[(l + f)/ 2];
    // std::cout << first << "\n\n" << last << "\n\n";
	while (arr[first] < mid)   
		first++;
	while (arr[last] > mid)
		last--;

	if (first <= last)
	{
        std::swap(arr[first], arr[last]);
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

uint16_t randomInt() {
	std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<uint16_t> uni(-1000, 1000);

	return uni(rng);
}

void printArr(int *arr)
{
    for (std::size_t i = 0; i < 1000; i++)
        std::cout << arr[i] << " ";
}

int main()
{
    int arr[1000];
    int array[1000];
    for (std::size_t i = 0; i < 1000; i++)
    {
        arr[i] = randomInt();
        array[i] = randomInt();
    
    }
    // printArr(arr);
    // std::cout << "\n\n";
    int bubbleSortOperators = bubbleSort(arr);
    quicksort(array, 0, 1000);
    std::cout << "Operations in bubble sort: " << bubbleSortOperators << std::endl;
    std::cout << "Operations in quick sort: " << quickSortOperations << std::endl;
    // printArr(arr);
    return 0;
}
