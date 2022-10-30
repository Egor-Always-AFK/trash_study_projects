#include "Remote.hpp"
#include "Tv.hpp"

Remote::Remote() : remoteOnOff(false)
{	}

Remote::Remote(const Remote &src)
{
	*this = src;
}

Remote::~Remote()
{	}

Remote &Remote::operator=(const Remote &src)
{
	if (this != &src)
		remoteOnOff = src.remoteOnOff;
	return *this;
}

std::string Remote::getMode()
{
	if (remoteOnOff == true)
		return "Remote in interactive mode\n";
	else
		return "Remote in normal mode\n";
}

void Remote::changeMode(Tv tv)
{
	if (tv.tvOnOff == true)
	{
		if (remoteOnOff == true)
			remoteOnOff = false;
		else
			remoteOnOff = true;
		std::cout << "Now " << this->getMode();
	}
	else
		throw Tv::TvIsOff();
}