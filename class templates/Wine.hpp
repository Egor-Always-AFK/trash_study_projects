#pragma once

#include <string>
#include <valarray>

using namespace std;

typedef valarray<int> Arrayint;
typedef pair<Arrayint, Arrayint> PairArray;

class Wine
{
public:
	Wine();
	Wine(const char* label, const int size, const int years[], const int bottles[]);
	Wine(const char* label, const int size);
	Wine(const char* label, const PairArray& pair);
	~Wine();

	void SetBottles();
	const char* Label();
	int sum();
	void Show();

private:
	string label;
	PairArray Pair;
	int size;
};