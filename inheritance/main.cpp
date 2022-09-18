# include "Classic.hpp"


char *ft_strcpy(const char *str, char *dst)
{
	size_t i = 0;
	
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i + 1] = '\0';
	return (dst);
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;

    while (str[i])
        i++;
    return (i);
}

void Bravo(const Cd &disk)
{
	disk.Report();
}

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2("Piano sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pсd = &c1;
	
	c1.Report();
	c2.Report();
	cout << "Using object directrly:\n";
	pсd->Report();
	pсd = &c2;
	pсd->Report();
	cout << "Calling a function with a CD reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assigment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return(0);
}