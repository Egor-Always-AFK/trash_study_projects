#ifndef FINK_HPP
#define FINK_HPP

#include "AEmployee.hpp"

class Fink : virtual public abstr_emp 
{
    private:
        std::string reportsto;
    protected:
        const std::string ReportsTo () const;
        std::string &ReportsTo ();
    public:
        Fink();
        Fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo) ;
        Fink (const abstr_emp &е, const std::string &rpo) ; 
        Fink (const Fink &е) ;
        virtual void ShowAll ( ) const;
        virtual void SetAll ( ) ;
};

#endif 
