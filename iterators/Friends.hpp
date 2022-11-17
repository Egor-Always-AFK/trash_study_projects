#ifndef FRIENDS_HPP
#define FRIENDS_HPP

#include <iostream>
#include <vector> 
#include <algorithm>

class Friends
{
	private:
		std::string _name;
	public:
		Friends();
		Friends(const std::string name);
		Friends(const Friends &src);
		~Friends();
		Friends operator=(const Friends &src);
		friend std::ostream &operator<<(std::ostream &out, Friends &src);

		std::string getName();
};

bool operator==(Friends &src1, Friends &src2);
#endif 
