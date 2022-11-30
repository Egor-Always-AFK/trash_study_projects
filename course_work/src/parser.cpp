#include "../incl/MainHeader.h"

std::size_t find_tokens(const char *str)
{
	std::size_t i = 0;
	std::size_t ret = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			ret++;
		i++;
	}
	return (ret + 1);
}

bool check_date_validation(int *date)
{
	if (date[0] < 0 || date[0] > 31)
		return false;
	else if (date[1] < 0 || date[1] > 12)
		return false;
	return true;
}

int *pars_date(const char *str)
{
	std::size_t i = 0;
	std::size_t tmp = 3;
	int *ret = new int[3];
	while (tmp != 0)
	{
		if (tmp != 0 && str[i] == ' ')
		{
			std::cout << "Invalid file input. Use format: day.month.year.\n";
			break;
		}
		int j = 0;
		std::string tmps;
		while (str[i] != '.' && str[i] != ' ')
		{
			tmps.push_back(str[i]);
			i++;
		}
		j += std::atoi(tmps.c_str());
		ret[3 - tmp] = j;
		tmp--;
		i++;
	}
	if (check_date_validation(ret) == false)
	{
		std::cout << "Invalid file input. Use format: 0 < day < 31 && 0 < month < 12.\n";
		return nullptr;
	}
	return ret;
}


std::string pars_number(const char *str)
{
	std::size_t i = 0;
	while (str[i] != ' ')
		i++;
	i++;
	std::string ret;
	while (str[i] != ' ')
	{
		ret.push_back(str[i]);
		i++;
	}
	return ret;
}

int pars_norm_hour(const char *str)
{
	std::size_t i = 0; 
	std::size_t count = 0;
	while (count < 2)
	{
		if (str[i] == ' ')
			count++;
		i++; 
	}

	std::string ret;
	while (str[i])
	{
		ret.push_back(str[i]);
		i++;
	}
	int norm_hour = std::atoi(ret.c_str());
	if (norm_hour < 0)
	{
		std::cout << "Norm hour must be positive integer!\n";
		return 0;
	}
	return norm_hour;
}


AutoService ft_split(const char *str)
{
	int *date = nullptr;
	std::string number;
	int norm_hour;
	if (find_tokens(str) != 3)
		std::cout << "Invalid fileinput. Use example file.\n";
	else
	{
		date = pars_date(str);
		number = pars_number(str);
		norm_hour = pars_norm_hour(str);
	}
	AutoService ret;
	if ((date != nullptr) && (number.size() != 0) && (norm_hour != 0))
	{
		ret = AutoService(date[0], date[1], date[2], number, norm_hour);
	}
	return ret;
}
