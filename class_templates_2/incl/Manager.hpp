#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "AEmployee.hpp"

class Manager : virtual public abstr_emp
{
	protected:
		int InChargeOf() const;
		int& InChargeOf();

	private:
		int inChargeOf; 

	public:
		Manager();
		Manager(const std::string& fn, const std::string& ln, const std::string& j, int ico);
		Manager(const abstr_emp& e, int ico);
		Manager(const Manager& m);
		virtual void ShowAll() const;
		virtual void SetAll();

   
};

#endif 
