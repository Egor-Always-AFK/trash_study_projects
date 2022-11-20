#include "Friends.hpp"

Friends::Friends() : _name("[DELETED]")
{   }

Friends::Friends(const std::string name) : _name(name)
{   }

Friends::Friends(const Friends &src) : _name(src._name)
{   }

Friends::~Friends()
{   }

Friends Friends::operator=(const Friends &src)
{
    if (this != &src)
        _name = src._name;
    return (*this);
}

bool operator==(Friends &src1, Friends &src2)
{
    if (src1.getName() == src2.getName())
        return true;
    return false;
}

bool operator!=(Friends &src1, Friends &src2)
{
    if (src1.getName() != src2.getName())
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &out, Friends &src)
{
    out << "\n" << "Friend name: " << src._name;
    return out;
}

std::string Friends::getName()
{
    return _name;
}

