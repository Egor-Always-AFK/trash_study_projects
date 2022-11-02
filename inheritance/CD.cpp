#include "CD.hpp"

Cd::Cd(const Cd &d)
{
	if (performas)
		delete[] performas;
	if (label)
		delete[] label;
	performas = new char[ft_strlen(d.performas) + 1];
	performas = ft_strcpy(d.performas, performas);
	label = new char[ft_strlen(d.label) + 1];
	label = ft_strcpy(d.label, label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performas = new char[50];
	performas = NULL;
	label = new char[50];
	label = NULL;
}

Cd::Cd(char *s1, char* s2, int n, double x)
{
	performas = new char[ft_strlen(s1) + 1];
	performas = ft_strcpy(s1, performas);
	label = new char[ft_strlen(s2) + 1];
	label = ft_strcpy(s2, label);
	selections = n;
	playtime = x;
}

Cd& Cd::operator=(const Cd &d)
{
	if (this == &d)
		return(*this);
	if (performas)
		delete[] performas;
	if (label)
		delete[] label;
	performas = new char[ft_strlen(d.performas) + 1];
	performas = ft_strcpy(d.performas, performas);
	label = new char[ft_strlen(d.label) + 1];
	label = ft_strcpy(d.label, label);
	selections = d.selections;
	playtime = d.playtime;

	return (*this);
}

Cd::~Cd()
{
	delete[] performas;
	delete[] label;
}

void Cd::Report() const
{
	cout << "CD info:\n1)CD performas: " << performas << "\n2)CD label: " << label \
		<< "\n3)CD selections: " << selections << "\n4)CD playtime:" << playtime << "\n";
}

