#ifndef HEADER_H
# define HEADER_H
#include <iostream>
#include <iomanip>
#include <random>


void hoare_sort(int size, int* array, size_t& count);

void sort_(int left, int right, int* arr, size_t& count);

void bubleSort(int* arr, size_t& bubleCounter, size_t arrSize);

#endif