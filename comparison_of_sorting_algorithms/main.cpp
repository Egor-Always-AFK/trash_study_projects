#include<iostream>
#include<random>
#include<chrono>
#include "header.h"

int randomize() 
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int32_t> uni(0, 1024);

	return uni(rng);
}

int main()
{
	const size_t arrSize = 1000;
	int arr[arrSize] ={};
	int forBuble[arrSize] = {};
	int forHoar[arrSize] = {};
	size_t bubleCounter = 0;
	size_t hoarCounter = 0;

	for(size_t i = 0; i < arrSize; i++)
	{
		arr[i] = randomize();
		forBuble[i] = arr[i];
		forHoar[i] = arr[i];
	}

	auto bubbleStart = std::chrono::steady_clock::now();
	bubleSort(forBuble, bubleCounter, arrSize);
	auto bubbleEnd = std::chrono::steady_clock::now();
	auto bubbleTime = std::chrono::duration_cast<std::chrono::nanoseconds>(bubbleEnd - bubbleStart);

	auto hoarStart = std::chrono::steady_clock::now();
	hoare_sort(arrSize, forHoar, hoarCounter);
	auto hoarEnd = std::chrono::steady_clock::now();
	auto hoarTime = std::chrono::duration_cast<std::chrono::nanoseconds>(hoarEnd - hoarStart);
	int timeProfit = bubbleTime.count()/hoarTime.count();
	int iterationsProfit = bubleCounter/hoarCounter; 

	std::cout << "\nBubble sort: " << (bubbleTime.count() * 0.000001) << " milliseconds " << bubleCounter << " iterations \n";
	std::cout << "Hoare sort: " << (hoarTime.count() * 0.000001) << " milliseconds " << hoarCounter << " iterations \n";
	std::cout << "Hoare coefficient profit:\ntime: " << timeProfit << "\niterations: " << iterationsProfit << std::endl;

	return 0;
}