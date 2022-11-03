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

std::ostream &operator<<(std::ostream &out, Review &src)
{
	out << "_name: " << src._name << "\n_rating: " << src._rating;
	return (out);
}

std::string Review::getName()
{
	return (_name);
}

std::size_t Review::getRating()
{
	return (_rating);
}