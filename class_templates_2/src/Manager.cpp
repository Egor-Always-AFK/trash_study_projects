#include "../incl/Manager.hpp"

int Manager::InChargeOf() const 
{ 
	return inChargeOf; 
}

int &Manager::InChargeOf() 
{ 
	return inChargeOf; 
}

Manager::Manager() : abstr_emp(), inChargeOf(0)
{  }

Manager::Manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j)
{
	this->inChargeOf = ico;
}

Manager::Manager(const abstr_emp &e, int ico) : abstr_emp(e)
{
	this->inChargeOf = ico;
}

Manager::Manager(const Manager &m) : abstr_emp(m)
{
	this->inChargeOf = m.inChargeOf;
}

void Manager::ShowAll() const
{
	std::cout << "\nManager:\n";
	abstr_emp::ShowAll();
	std::cout << "\nChargeOf: " << inChargeOf;
}

void Manager::SetAll()
{
	abstr_emp::SetAll();
	inChargeOf = 0;
}