#include "Tv.hpp"
#include "Remote.hpp"

const char *Tv::TvIsOff::what() const throw()
{
	return "Warning!\nTv is off";
}	

void Tv::changeRemoteMode(Remote rem)
{
	rem.changeMode(*this);
}

Tv::Tv()
{
	this->tvOnOff = false;
}

Tv::Tv(bool oof)
{	
	this->tvOnOff = oof;
}

Tv::~Tv()
{	}

bool Tv::getMode()
{
	return tvOnOff;
}

void Tv::onOff()
{
	if (tvOnOff == false)
		tvOnOff = true;
	else
		tvOnOff = false;
}