#include "../incl/Fink.hpp"

const std::string Fink::ReportsTo () const 
{ 
	return reportsto;
} 

std::string &Fink::ReportsTo()
{
	return reportsto;
}

Fink::Fink() : abstr_emp("Default", "Default", "Default"), reportsto("Default")
{	}

Fink::Fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo)
{	}

Fink::Fink(const Fink &e) : reportsto(e.reportsto)
{	}

void Fink::ShowAll() const
{
	std::cout << "Fink: reportsto: " << reportsto << std::endl;
	abstr_emp::ShowAll();
}

void Fink::SetAll()
{
	reportsto = "[DELETED]";
	abstr_emp::SetAll();
}