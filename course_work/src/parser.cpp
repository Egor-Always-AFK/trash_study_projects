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
	return ret;
}

bool check_date_validation(int *date)
{
	if (date[0] < 0 && date[0] > 31)
		return false;
	else if (date[1] < 0 && date[1] > 12)
		return false;
	return true;
}

int *pars_date(const char *str)
{
	std::size_t i = 0;
	std::size_t tmp = 3;
	int ret[3];
	while (tmp != 0)
	{
		if (tmp != 0 && str[i] == ' ')
		{
			std::cout << "Invalid file input. Use format: day.month.year.\n";
			break;
		}
		std::size_t j = 0;
		while (str[i] != '.')
		{
			j *= 10;
			j += static_cast<std::size_t>(str[i]);
			i++;
		}
		ret[3 - tmp] = j;
		tmp--;
	}
	if (check_date_validation(ret) == false)
	{
		std::cout << "Invalid file input. Use format: 0 < day < 31 && 0 < month < 12";
		return nullptr;
	}
	return ret;
}

AutoService ft_split(const char *str)
{
	if (find_tokens(str) != 3)
		std::cout << "Invalid fileinput. Use example file.";
	else
	{
		int *date = pars_date(str);
		if (date)
			return ;
		
	}
	std::vector<std::string> ret;
	return ret;
}
