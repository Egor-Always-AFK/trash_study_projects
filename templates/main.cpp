#include <iostream>
using namespace std;

int ft_strlen(const char *arr)
{
	int i = 0;
	while (arr[i])
		i++;
	return(i);
}

template <typename T>
T maxn(T *arr)
{
	int i = 0;
	T max = -2147483647;
	while (arr[i])
	{
		if (arr[i] > max)   
			max = arr[i];
		i++;
	}
	return (max);
}

template <typename T>
T maxn(T *array, size_t size)
{
	int maxLength = ft_strlen(array[0]);
	const char* maxString = array[0];
	for (int i = 1; i < size; i++)
	{
		int length = ft_strlen(array[i]);
		if (maxLength < length) 
		{
			maxLength = length;
			maxString = array[i];
		}
	}
	return maxString;	
}

int main()
{
	int arr[6] = {1, 2, 6, 4, 5, 3};
	cout << maxn(arr);
	double arr_2[4] = {1.7, 10.8, 1.9, 2.2};
	cout << "\n" << maxn(arr_2) << "\n";
	const char* charPtrArray[] = {"hi", "very long str", "idk maybe this very very long str", "sooorry"};
	cout << maxn(charPtrArray, 4) << "\n";
}
