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

std::vector<Friends> ft_unique(std::vector<Friends> vec)
{
	std::vector<Friends> ret;
	std::vector<Friends>::iterator vec_end = vec.end();
	for (std::vector<Friends>::iterator vec_start = vec.begin(); vec_start < (vec_end - 1); vec_start++)
	{
		if (*(vec_start) == *(vec_start + 1))
			vec_start++;
		else
			ret.push_back(*(vec_start));
	}
	return ret;
}

std::vector<Friends> newList(std::vector<Friends> list1, std::vector<Friends> list2)
{
	for (std::vector<Friends>::iterator list2_start = list2.begin(); list2_start != list2.end(); list2_start++)
		list1.push_back(*list2_start);
	std::sort(list1.begin(), list1.end(), [](Friends vec1, Friends vec2) {
            return vec1.getName().compare(vec2.getName()) < 0;
	});
	if (list1.size() == 2)
	{
		std::vector<Friends>::iterator tmp = list1.begin();
		if (*(tmp) != *(tmp + 1))
			return list1;
	}
	std::vector<Friends> ret = ft_unique(list1);
	return ret;
}

int main()
{
	{
		std::cout << "\n--FIRST TEST START--\n";
		std::vector<Friends> list1;
		list1.push_back(Friends("cat"));
		list1.push_back(Friends("dog"));
		list1.push_back(Friends("cow"));
		list1.push_back(Friends("bird"));
		list1.push_back(Friends("chicken"));
		printSortNameList(list1);
		std::cout << "\n\n";
		std::vector<Friends> list2;
		list2.push_back(Friends("Capybara"));
		list2.push_back(Friends("cat"));
		list2.push_back(Friends("bird"));
		list2.push_back(Friends("Pallas cat"));
		list2.push_back(Friends("Tiger"));
		printSortNameList(list2);

		std::vector<Friends> finalList = newList(list1, list2);
		std::cout << "\nA list with unique names:";
		printSortNameList(finalList);
		std::cout << "\n--FIRST TEST END--\n";
	}
	{
		std::cout << "\n--SECOND TEST START--\n";
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
		std::cout << "\n\n";
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
		std::cout << "\nA list with unique names:";
		printSortNameList(finalList);
		std::cout << "\n--SECOND TEST END--\n";
		return 0;
	}
}