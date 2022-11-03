#ifndef REVIEW_HPP
# define REVIEW_HPP

#include <iostream>

class Review
{
	private:
		std::string _name;
		std::size_t _rating;
	
	public:
		Review();
		Review(const std::string name, const std::size_t rating);
		Review(const Review &src);

		~Review();

		Review &operator=(const Review &src);
};

#endif