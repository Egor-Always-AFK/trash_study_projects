#include "../incl/Highfink.hpp"

Highfink::Highfink() : Manager(), Fink()
{
	ReportsTo() = "Default";
	InChargeOf() = 0;
}

Highfink::Highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico) : abstr_emp(fn, ln, j)
{
	ReportsTo() = rpo;
	InChargeOf() = ico;
}

Highfink::Highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e)
{
	ReportsTo() = rpo;
	InChargeOf() = ico;
}

Highfink::Highfink(const Fink &f, int ico) : Fink(f)
{
	InChargeOf() = ico;
}

Highfink::Highfink(const Manager &m, const std::string &rpo) : Manager(m)
{
	ReportsTo() = rpo;
}

Highfink::Highfink(const Highfink & h) : abstr_emp(h)
{
	InChargeOf() = h.InChargeOf();
	ReportsTo() = h.ReportsTo();
}

void Highfink::ShowAll() const
{
	std::cout << "\nHighfink:\n";
	abstr_emp::ShowAll();
	std::cout << "\nChargeOf: " << InChargeOf() << "\nReportsTo: " << ReportsTo();
}

void Highfink::SetAll() 
{
    Manager::SetAll();
    Fink::SetAll();
}