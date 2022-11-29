#include "../incl/MainHeader.h"

void menu()
{
	std::cout << "Enter:\n0 - for input,\n1 - for file input," <<
		"\n2 - for sort,\n3 - for search element," <<  
		"\n4 - for edit element,\n5 - for exit\n";
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
			ft_split(tmp);
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