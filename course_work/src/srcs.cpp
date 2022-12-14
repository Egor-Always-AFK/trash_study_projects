#include "../incl/MainHeader.h"

void menu()
{
	std::cout << "Enter:\n" << INPUT << " - for input,\n" << FILEINPUT << " - for file input,\n" <<
		FILEOUTPUT << " - for file output,\n" << OUTPUT << " - for output,\n" <<  
		SORT << " - for sort,\n" << SEARCH << " - for search,\n" << 
		EDIT << " - for edit element,\n" << EXIT << " - for exit.\n";
}

int input()
{
	int value;
	while (!(std::cin >> value))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Enter digit!\n>>";
	}
	return value;
}

void fileOutput(std::vector<AutoService> vec)
{
	std::ofstream out;
	std::string name;
	std::cout << "Enter name of file:\n>>";
	std::cin >> name;
	out.open(name.c_str());
	if (out.is_open())
	{
		for (std::vector<AutoService>::iterator vec_begin = vec.begin(); vec_begin != vec.end(); vec_begin++)
			out << (*vec_begin) << std::endl;
	}
	else
	{
		std::cout << "Error! File can't open.\n";
	}
	out.close();
}

void search(std::vector<AutoService> vec)
{

	int *date = new int[3];
	std::cout << "Enter date:\n";
	std::cin >> date[0] >> date[1] >> date[2];
	int tmp = 0;
	std::cout << "Search result:\n";
	for (std::vector<AutoService>::iterator vec_begin = vec.begin(); vec_begin != vec.end(); vec_begin++)
	if ((*vec_begin).getDataDay() == date[0] && (*vec_begin).getDataMonth() == date[1] && (*vec_begin).getDataYear() == date[2])
	{
		std::cout << '\n' << (*vec_begin) << std::endl;
		tmp++;
	}
	if (tmp == 0)
		std::cout << "Not found.\n";
	delete [] date;
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
	file.close();
	return ret;
}

std::vector<AutoService> manualInput()
{
	std::cout << "Input number of clients:\n>>";
	int number;
	std::cin >> number;
	if (number <= 0)
	{
		std::cout << "Invalid number!\n";
	}
	else
	{
		std::vector<AutoService> ret;
		for (int i = 0; i != number; i++)
		{
			std::cout << "Enter date(day month year):\n";
			int *date = new int[3];
			std::cin >> date[0] >> date[1] >> date[2];
			std::cout << "Enter number:\n";
			std::string number;
			std::cin >> number;
			std::cout << "Enter normhour:\n";
			int normhour;
			std::cin >> normhour;
			if (check_date_validation(date) == false)
			{
				std::cout << "Error! date must be right!\n";
				i--;
			}
			else
			{
				AutoService service = AutoService(date[0], date[1], date[2], number, normhour);
				ret.push_back(service);
			}
		}
		return ret;
	}
	std::vector<AutoService> ret_null;
	return ret_null;
}

std::vector<AutoService> addVectorAtVector(std::vector<AutoService> dst, std::vector<AutoService> src)
{
	for (std::vector<AutoService>::iterator src_begin = src.begin(); src_begin != src.end(); src_begin++)
		dst.push_back((*src_begin));
	return dst;
}

std::vector<AutoService> sort(std::vector<AutoService> vec)
{
std::cout << "Sort by\n" << DATE << " - date,\n" << NUMBER << " - number\n" << NORMHOUR << " - normhour\n"; 
	int choise = 0;
	std::cin >> choise;
	std::cout << "Search result:\n";
	switch(choise)
	{
		case DATE:
		{
			std::sort(vec.begin(), vec.end(), [](AutoService vec_1, AutoService vec_2) {
        	    return vec_1.getDataYear() < vec_2.getDataYear();
    		});
			return vec;
			break;
		}
		case NUMBER:
		{
			std::sort(vec.begin(), vec.end(), [](AutoService vec_1, AutoService vec_2) {
        	    return vec_1.getNumber().compare(vec_2.getNumber()) < 0;
    		});
			return vec;
			break;
		}
		case NORMHOUR:
		{
			std::sort(vec.begin(), vec.end(), [](AutoService vec_1, AutoService vec_2) {
        	    return vec_1.getNormHour() < (vec_2.getNormHour());
    		});
			return vec;
			break;
		}
		default:
		{
			std::cout << "try harder!\n";
			break;
		}
	}
	return vec;
}

std::vector<AutoService> edit(std::vector<AutoService> vec)
{
	std::cout << "Enter what parametr u want edit:\n" << DATE << " - for editing date,\n" << NUMBER << " - for editing number,\n" << NORMHOUR << " - for editing normhour.\n>>";
	int choise;
	std::cin >> choise;
	output(vec);
	std::cout << "What date you wan't edit?(enter number of client).\n>>";
	std::string tmp;
	std::cin >> tmp;
	switch (choise)
	{
		case DATE:
		{
			std::vector<AutoService>::iterator vec_it = vec.begin();
			for (std::vector<AutoService>::iterator vec_begin = vec.begin(); vec_begin != vec.end(); vec_begin++)
			{
				vec_it = vec_begin;
				if (tmp == (*vec_begin).getNumber())
					break;
			}
			std::cout << "Enter date:\nday\n>>";
			int tmpr;
			std::cin >> tmpr;
			(*vec_it).setDataDay(tmpr);
			std::cout << "Month\n>>";
			std::cin >> tmpr;
			(*vec_it).setDataMonth(tmpr);
			std::cout << "Year\n>>";
			std::cin >> tmpr;
			(*vec_it).setDataYear(tmpr);
			break;
		}
		case NUMBER:
		{
			for (std::vector<AutoService>::iterator vec_begin = vec.begin(); vec_begin != vec.end(); vec_begin++)
			{
				if (tmp == (*vec_begin).getNumber())
				{
					std::string tmps;
					std::cout << "Enter number:\n>>";
					std::cin >> tmps;
					(*vec_begin).setAutoNumber(tmps);
				}
			}
			break;
		}
		case NORMHOUR:
		{
			for (std::vector<AutoService>::iterator vec_begin = vec.begin(); vec_begin != vec.end(); vec_begin++)
			{
				if (tmp == (*vec_begin).getNumber())
				{
					int tmpi;
					std::cout << "Enter normhour:\n>>";
					std::cin >> tmpi;
					(*vec_begin).setNormHour(tmpi);
				}
			}
			break;
		}
	default:
		std::cout << "Try harder!\n";
		break;
	}
	return vec;
}

void output(std::vector<AutoService> vec)
{
	std::size_t i = 0;
	std::vector<AutoService>::iterator vec_begin = vec.begin();
	while (i != vec.size())
	{
		std::cout << *(vec_begin) << "\n";
		i++;
		vec_begin++;
	}
}	