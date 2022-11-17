#include "Friends.hpp"

void printSortNameList(std::vector<Friends> vec)
{
	std::sort(vec.begin(), vec.end(), [](Friends vec1, Friends vec2) {
            return vec1.getName().compare(vec2.getName()) < 0;
    });
	std::vector<Friends>::iterator iter = vec.end();
	for (std::vector<Friends>::iterator it = vec.begin(); it != iter; it++)
		std::cout << (*it);
}

std::vector<Friends> newList(std::vector<Friends> list1, std::vector<Friends> list2)
{
	std::vector<Friends> ret;
	std::vector<Friends>::iterator list1_end = list1.end();
	std::vector<Friends>::iterator list2_end = list2.end();
	for (std::vector<Friends>::iterator list2_start = list2.begin(); list2_start != list2_end; list2_start++)
		list1.push_back(*list2_start);
	std::sort(list1.begin(), list1.end(), [](Friends vec1, Friends vec2) {
            return vec1.getName().compare(vec2.getName()) < 0;
	});
	for (std::vector<Friends>::iterator list1_start = list1.begin(); list1_start != (list1_end - 1); list1_start++)
	{
		if (*(list1_start + 1) == *(list1_start))
			;
		ret.push_back(*list1_start);
	}
	// printSortNameList(ret);
	return ret;
}

int main()
{

	std::cout << "Matt wants to invite guests. Enter how many guests to invite Matt\n>>";
	int j;
	std::cin >> j;
	std::vector<Friends> list1;
	for (int i = 0; i < j; i++)
	{
		std::cout << "Enter friend name:\n>>";
		std::string name;
		std::cin >> name;
		list1.push_back(Friends(name));
	}
	printSortNameList(list1);
	std::cout << "\nPatt wants to invite guests. Enter how many guests to invite Patt\n>>";
	std::cin >> j;
	std::vector<Friends> list2;
	for (int i = 0; i < j; i++)
	{
		std::cout << "Enter friend name:\n>>";
		std::string name;
		std::cin >> name;
		list2.push_back(Friends(name));
	}
	printSortNameList(list2);

	std::vector<Friends> finalList = newList(list1, list2);
	// std::cout << "\nA list with unique names:";
	// printSortNameList(finalList);

	return 0;
}