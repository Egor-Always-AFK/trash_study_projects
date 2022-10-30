#ifndef HIGHFINK_HPP
#define HIGHFINK_HPP

#include "Manager.hpp"
#include "Fink.hpp"

class Highfink: public Manager, public Fink
{
	public :
		Highfink() ;
		Highfink (const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico) ;
		Highfink (const abstr_emp &е, const std::string &rpo, int ico) ; 
		Highfink (const Fink &f, int ico) ;
		Highfink (const Manager & m, const std::string & rpo) ;
		Highfink (const Highfink & h) ;
		virtual void ShowAll() const;
		virtual void SetAll();
};

#endif
