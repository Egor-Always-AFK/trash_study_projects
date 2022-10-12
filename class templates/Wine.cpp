#include "Wine.hpp"


Wine::Wine() : label("no name"), Pair(), size() {}

Wine::Wine(const char* label, const int size, const int years[], const int bottles[])
{
    this->label = label;
    this->size = size;
    Pair.first = Array(size);
    Pair.second = Array(size);

    for (size_t i = 0; i < size; i++)
    {
        Pair.first[i] = years[i];
        Pair.second[i] = bottles[i];
    }

}

Wine::Wine(const char* label, const int size)
{
    this->label = label;
    this->size = size;
    Pair.first = Array(size);
    Pair.second = Array(size);
}

Wine::Wine(const char* label, const PairS& pair)
{
    this->label = label;
    size = pair.first.size();

    for (size_t i = 0; i < size; i++)
    {
        this->Pair.first[i] = pair.first[i];
        this->Pair.second[i] = pair.second[i];
    }
}

void Wine::SetBottles()
{
    cout << "Enter " << Label() << " data for " << size << " year(s):\n";

    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter year: ";
        cin >> Pair.first[i];
        cout << "Enter bottles for that year: ";
        cin >> Pair.second[i];
    }
    cout << endl;
}

const char* Wine::Label()
{
    return label.c_str();
}

int Wine::sum()
{
    return Pair.second.sum();
}

void Wine::Show()
{
    cout << "Wine: " << Label() << "\n";
    cout << setw(10) << "Year" << "\t" << "Bottles\n";

    for (size_t i = 0; i < Pair.first.size(); i++)
        cout << setw(10) << Pair.first[i] << "\t" << Pair.second[i] << "\n";
    cout << "\n";
}

Wine::~Wine()
{
    this->label.clear();
}