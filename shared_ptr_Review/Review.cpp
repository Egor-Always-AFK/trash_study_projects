#include "Review.hpp"

Review::Review() : _name("Default"), _rating(0)
{   }

Review::Review(const std::string name, const std::size_t rating) : _name(name), _rating(rating)
{   }

Review::Review(const Review &src)
{
	if (this != &src)
		*this = src;
}

Review::~Review()
{	}

Review &Review::operator=(const Review &src)
{
	_name = src._name;
	_rating = src._rating;

	return (*this);
}