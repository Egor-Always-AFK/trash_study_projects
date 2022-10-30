#ifndef TV_HPP
#define TV_HPP

#include "Remote.hpp"
#include <iostream>

class Remote;

class Tv
{
	private:
		bool tvOnOff;
		friend class Remote;
	public:
		void changeRemoteMode(Remote rem);
		class TvIsOff : public std::exception {
			const char *what() const throw();
		};
		
		Tv();
		Tv(bool oof);
		~Tv();

		bool getMode();
		
		void onOff();
};

#endif 
