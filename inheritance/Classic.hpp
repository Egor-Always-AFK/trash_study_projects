#include "CD.hpp"

char *ft_strcpy(const char *str, char *dst);

size_t ft_strlen(const char *str);

class Classic : public Cd {
	private:

	char *idk;
	
	public:

	Classic(char *s1, char* s2, char* s3, int n, double x);
	Classic();
	Classic(const Classic &c);
	Classic & operator = (const Classic& c);
	void Report() const override;
};
