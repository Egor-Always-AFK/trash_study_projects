#include "header.h"

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