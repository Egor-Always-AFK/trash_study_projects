#ifndef REVIEW_HPP
# define REVIEW_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


#define FALSE 0
#define TRUE 1
#define NAME 0
#define RATING 1

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
		friend std::ostream &operator<<(std::ostream &out, Review &src);


		std::string getName();
		std::size_t getRating();
};


#endif