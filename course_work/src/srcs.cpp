#include "../incl/MainHeader.h"

void menu()
{
	std::cout << "Enter:\n0 - for input,\n1 - for file input," <<
		"\n2 - for file output,\n3 - for output," <<  
		"\n4 - for sort,\n5 - for search, " << 
		"\n6 - for edit element,\n7 - for exit.";
}

void search(std::vector<AutoService> vec)
{
	std::cout << "WIP\n0 - date,\n1 - number\n2 - normhour\n"; 
	int choise = 0;
	std::cin >> choise;
	switch(choise)
	{
		case DATE:
		{
			int *date;
			std::cout << "Enter date.";
			std::cin >> date[0] >> date[1] >> date[2];
			int tmp = 0;
			for (std::vector<AutoService>::iterator vec_begin = vec.begin(); vec_begin != vec.end(); vec_begin++)
			{
				if (*(vec_begin).)
			}
			break;
		}
		case NUMBER:

			break;

		case NORMHOUR:

			break;
		default:
		{
			std::cout << "try harder!\n";
			break;
		}
	}
}

std::vector<AutoService> fileInput()
{
	std::string fileName;
	std::cout << "Enter file name for file input.\n>>";
	std::cin >> fileName;
	std::vector<AutoService> ret;
	std::ifstream file;
	file.open(fileName.c_str());
	if (file.is_open() == 1)
	{
		std::string str;
		while (std::getline(file, str))
		{
			const char *tmp = str.c_str();
			ret.push_back(ft_split(tmp));
		}
	}
	else
	{
		std::cout << "invalid filename\n";
		std::vector<AutoService> ret_null;
		return ret_null;
	}
	return ret;
}