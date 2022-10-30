#ifndef REMOTE_HPP
#define REMOTE_HPP


#include <iostream>
#include "Tv.hpp"

class Tv;

class Remote
{
	private:
		bool remoteOnOff;
	public:
		friend class Tv;
		class RemoteAlreadyNormal : public std::exception{
				const char *what() const throw();
		};
		class RemoteAlreadyInteractive : public std::exception{
				const char *what() const throw();
		};
		Remote();
		Remote(bool oof);
		Remote(const Remote &src);
		void changeMode(Tv tv);
		std::string getMode();

		~Remote();

		Remote &operator=(const Remote &src);

};

#endif
