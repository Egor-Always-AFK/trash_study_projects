#include "../incl/Employee.hpp"

Employee::Employee() : abstr_emp("Default", "Default", "Default")
{   }

Employee::Employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j)
{   }

void Employee::SetAll()
{
	abstr_emp::SetAll();
}

void Employee::ShowAll() const
{
	std::cout << "Employee:\n";
	abstr_emp::ShowAll();
}