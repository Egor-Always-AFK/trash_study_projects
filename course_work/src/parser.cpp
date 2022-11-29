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
		while (str[i] != '.')
		{
			tmps.push_back(str[i]);
			i++;
			// std::cout << i << "\n
		}
		// std::cout << tmps << "\n";
		j *= tmps.size();
		j += std::atoi(tmps.c_str());
		std::cout << j << "\n";
		ret[2 - tmp] = j;
		// std::cout << "suck my linux " << ret[2 - tmp] << tmp << std::endl;
		tmp--;
		i++;
	}
	if (check_date_validation(ret) == false)
	{
		std::cout << "Invalid file input. Use format: 0 < day < 31 && 0 < month < 12";
		return nullptr;
	}
	// std::cout << "day: " << ret[0] << "\nmonth: " << ret[1] << "\nyear: " << ret[2] << "\n";
	return ret;
}

AutoService ft_split(const char *str)
{
	// std::cout << find_tokens(str);
	if (find_tokens(str) != 3)
		std::cout << "Invalid fileinput. Use example file.\n";
	else
	{
		pars_date(str);
		// int *date = pars_date(str);
	}
	AutoService ret;
	return ret;
}
