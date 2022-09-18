#include "Classic.hpp"

Classic::Classic() : Cd()
{
	idk = new char[5];
	idk = NULL;
}

Classic::Classic(const Classic &c) : Cd(c)
{
	this->idk = new char[ft_strlen(c.idk) + 1];
	this->idk = ft_strcpy(c.idk, this->idk);
}

Classic::Classic(char *s1, char* s2, char *s3, int n, double x) : Cd(s1, s2, n, x)
{
	idk = new char[(int)ft_strlen(s3) + 1];
	idk = ft_strcpy(s3, idk);
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return (*this);
	idk = new char[ft_strlen(c.idk) + 1];
	idk = ft_strcpy(c.idk, idk);

	return (*this);

}

void Classic::Report() const
{
	cout << "Main audio: " << idk << "\n";
}