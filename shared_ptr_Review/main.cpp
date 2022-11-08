#include "Review.hpp"

bool ft_find(std::vector<std::shared_ptr<Review>> min, std::vector<std::shared_ptr<Review>>::iterator start, int path)
{
	if (path == NAME)
	{
		std::vector<std::shared_ptr<Review>>::iterator min_end = min.end();

		for (std::vector<std::shared_ptr<Review>>::iterator min_start = min.begin(); min_start != min_end; min_start++)
			if ((**min_start).getName() == (**start).getName())
				return TRUE;
		return FALSE;
	}
	else if (path == RATING)
	{
		std::vector<std::shared_ptr<Review>>::iterator min_end = min.end();

		for (std::vector<std::shared_ptr<Review>>::iterator min_start = min.begin(); min_start != min_end; min_start++)
			if ((**min_start).getRating() == (**start).getRating())
				return TRUE;
		return FALSE;
	}
	return (TRUE);
}

// std::vector<std::shared_ptr<Review>> ft_find_min()
// {

// }

std::vector<std::shared_ptr<Review>> sorAtName(std::vector<std::shared_ptr<Review>> vec)
{
	std::vector<std::shared_ptr<Review>>::const_iterator end = vec.end();
	std::vector<std::shared_ptr<Review>> out;
	std::vector<std::shared_ptr<Review>>::iterator min;
	for (std::vector<std::shared_ptr<Review>>::iterator start = vec.begin(); start != end; start++)
	{
		min = vec.begin();
		for (std::vector<std::shared_ptr<Review>>::iterator tmp = vec.begin(); tmp != end; tmp++)
		{
			if ((**min).getName() < (**tmp).getName() && (ft_find(out, tmp, NAME) == FALSE))
				min = tmp;
		}
		out.push_back(*min);
	}

	return out;
}

std::vector<std::shared_ptr<Review>> sortAtRating(std::vector<std::shared_ptr<Review>> vec)
{
	std::vector<std::shared_ptr<Review>>::const_iterator end = vec.end();
	std::vector<std::shared_ptr<Review>> out;
	std::vector<std::shared_ptr<Review>>::iterator min;
	for (std::vector<std::shared_ptr<Review>>::iterator start = vec.begin(); start != end; start++)
	{
		min = vec.begin();
		for (std::vector<std::shared_ptr<Review>>::iterator tmp = vec.begin(); tmp != end; tmp++)
		{
			if (((**min).getRating() < (**tmp).getRating()) && (ft_find(out, tmp, RATING) == FALSE))
				min = tmp;
		}
		out.push_back(*min);
	}
	
	std::cout << "-----\nSorted vector(by rating):\n";
	for (std::vector<std::shared_ptr<Review>>::iterator start = out.begin(); start != out.end(); start++)
		std::cout << (**start) << "\n";
	return out;
}

int main()
{
	// std::vector<std::shared_ptr Review> vector = {Review(), Review("idk", 100), Review("wow", 2)};
	std::vector<std::shared_ptr<Review>> vec;
	vec.push_back(std::make_shared<Review>());
	vec.push_back(std::make_shared<Review>("test0", 100));
	vec.push_back(std::make_shared<Review>("test1", 2));
	vec.push_back(std::make_shared<Review>("test1", 123));

	vec = sorAtName(vec);
	std::cout << "Sorted vector(by name):\n";
	for (std::vector<std::shared_ptr<Review>>::iterator start = vec.begin(); start != vec.end(); start++)
		std::cout << (**start) << "\n";
	
	vec = sortAtRating(vec);

	return (0);
}