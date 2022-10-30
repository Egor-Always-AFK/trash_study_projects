#include "../incl/AEmployee.hpp"

abstr_emp::abstr_emp() : fname("Default"), lname("Default"), job("Default")
{   }

abstr_emp::abstr_emp(const std::string &fn, const std::string &ln, const std::string &j): fname(fn), lname(ln), job(j)
{	}

abstr_emp::abstr_emp(const abstr_emp &e) : fname(e.fname), lname(e.lname), job(e.job)
{	}

abstr_emp::~abstr_emp()
{	}

void abstr_emp::SetAll()
{
	fname = "[DELETED]";
	lname = "[DELETED]";
	job = "[DELETED]";
}

void abstr_emp::ShowAll() const
{
	std::cout << *this;
}

std::ostream &operator<<(std::ostream &out, const abstr_emp &ae)
{
	out << "First name: " << ae.fname << "\nLast name: " << ae.lname << "\nJob: " << ae.job;
	return out;
}