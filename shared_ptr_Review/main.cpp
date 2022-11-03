#include "Review.hpp"

void printSorAtName(std::vector<std::shared_ptr<Review>> vec)
{
	std::vector<std::shared_ptr<Review>>::const_iterator end = vec.end();
	std::vector<std::shared_ptr<Review>> out;
	std::vector<std::shared_ptr<Review>> min;
	for (std::vector<std::shared_ptr<Review>>::iterator start = vec.begin(); start != end; start++)
	{
		
		for (std::vector<std::shared_ptr<Review>>::iterator tmp = vec.begin() + 1; tmp != end; tmp++)
		{
			if (((**tmp).getName() > (**(tmp - 1)).getName()))
				if (std::find())
				std::cout << (**start) << "\n";
				// min.push_back(*(tmp - 1));
		}	
	}

	// end = min.end();
	// for (std::vector<std::shared_ptr<Review>>::iterator start = min.begin(); start != end; start++)
	// 	std::cout << (**start) << "\n";
}
int main()
{
	// std::vector<std::shared_ptr Review> vector = {Review(), Review("idk", 100), Review("wow", 2)};
	std::vector<std::shared_ptr<Review>> vec;
	vec.push_back(std::make_shared<Review>());
	vec.push_back(std::make_shared<Review>("idk", 100));
	vec.push_back(std::make_shared<Review>("wow", 2));

	printSorAtName(vec);
	return (0);
}