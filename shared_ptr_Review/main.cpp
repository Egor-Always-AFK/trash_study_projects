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

void sorAtName(std::vector<std::shared_ptr<Review>> vec)
{
	std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Review> reviewPtr_1, std::shared_ptr<Review> reviewPtr_2) {
            return reviewPtr_1.get()->getName().compare(reviewPtr_2.get()->getName()) < 0;
    });
	std::cout << "Sorted vector(by name):\n";
	for (std::vector<std::shared_ptr<Review>>::iterator start = vec.begin(); start != vec.end(); start++)
		std::cout << (**start) << "\n-----\n";
}

void sortAtRating(std::vector<std::shared_ptr<Review>> vec)
{
	std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Review> reviewPtr_1, std::shared_ptr<Review> reviewPtr_2) {
            return reviewPtr_1.get()->getRating() < reviewPtr_2.get()->getRating();
    });
	std::cout << "\nSorted vector(by rating):\n";
	for (std::vector<std::shared_ptr<Review>>::iterator start = vec.begin(); start != vec.end(); start++)
		std::cout << (**start) << "\n-----\n";
}

int main()
{
	std::vector<std::shared_ptr<Review>> vec;
	vec.push_back(std::make_shared<Review>());
	vec.push_back(std::make_shared<Review>("3", 123));
	vec.push_back(std::make_shared<Review>("1", 100));
	vec.push_back(std::make_shared<Review>("2", 2));

	sorAtName(vec);
	sortAtRating(vec);

	return (0);
}