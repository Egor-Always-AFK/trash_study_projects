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
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10};
	cout << maxn(arr);
	double arr_2[10] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.2};
	cout << "\n" << maxn(arr_2) << "\n";
	const char* charPtrArray[] = {"str", "very long str", "VERY LONG STR", "short str"};
	cout << maxn(charPtrArray, 4) << "\n";
}
