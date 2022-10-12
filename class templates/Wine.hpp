#pragma once

#include <string>
#include <valarray>
#include <iostream>
#include <iomanip>

using namespace std;

typedef valarray<int> Array;
typedef pair<Array, Array> PairS;

class Wine
{
public:
	Wine();
	Wine(const char* label, const int size, const int years[], const int bottles[]);
	Wine(const char* label, const int size);
	Wine(const char* label, const PairS& pair);
	~Wine();

	void SetBottles();
	const char* Label();
	int sum();
	void Show();

private:
	string label;
	PairS Pair;
	int size;
};