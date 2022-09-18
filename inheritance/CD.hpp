#include <iostream>
#include <string.h>
using namespace std;

char *ft_strcpy(const char *str, char *dst);

size_t ft_strlen(const char *str);

class Cd
{
	private:
	
	char *performas;
	char *label;
	int selections;
	double playtime;
	
	public:

	Cd(char *s1, char* s2, int n, double x);
	Cd(const Cd &d);
	Cd();
	~Cd();
	virtual void Report() const;
	Cd & operator = (const Cd& d);

};
