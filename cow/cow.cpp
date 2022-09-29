#include <iostream>

using namespace std;

size_t ft_strlen(const char *str)
{
    size_t i = 0;

    while (str[i])
        i++;
    return (i);
}

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

class Cow
{
    private:
        char *hobby;
        char *name;
        double weight;
    public:
        Cow();
        Cow(const char *nm, const char* ho, double weight);
        Cow(const Cow &c);
        ~Cow();
        Cow &operator=(const Cow &c);
        void ShowCow() const;
};

Cow::Cow()
{
    name = new char[0];
    hobby = new char[0];
}

Cow::Cow(const char *nm, const char *ho, double weight)
{
    name = new char[(int)ft_strlen(nm) + 1];
    hobby = new char[(int)ft_strlen(ho) + 1];
    name = ft_strcpy(nm, name);
    hobby = ft_strcpy(ho, hobby);

    this->weight = weight;
}

Cow& Cow::operator=(const Cow &c)
{
    if (this == &c)
        return (*this);
    if (name)
        delete[] name;
    if (hobby)
        delete[] hobby;
        
    size_t name_size, hobby_size;
    name = new char[(int)ft_strlen(c.name) + 1];
    hobby = new char[(int)ft_strlen(c.hobby) + 1];
    name = ft_strcpy(c.name, name);
    hobby = ft_strcpy(c.hobby, hobby);
    this->weight = c.weight;

    return (*this);
}

Cow::~Cow()
{
    cout << "\nCow " << name << " are deleted! :c";
    delete[] name;
    delete[] hobby;
}

void Cow::ShowCow() const
{
    cout << "Cow say moo:\nCow name: " << name << "\nCow hobby: " << hobby << "\nCow weight = " << weight << "\n";
}

int main()
{
    Cow dst("Molly", "Grass", 100.0);
    dst.ShowCow();
    cout << "\n";
    Cow tmp("wow", "wow2", 1213);
    tmp.ShowCow();
    cout << "\n";
    dst = tmp;
    dst.ShowCow();
}

