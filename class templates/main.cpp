#include "Wine.hpp"




int main()
{
    cout << "Enter name of wine: "; 
    string label;
    cin >> label;

    cout << "Enter number of bottles: "; 
    int years;
    cin >> years;

    Wine wine_1(label.c_str(), years); 
    wine_1.SetBottles(); 
    wine_1.Show(); 

    const int YEARS = 3;
    int y[YEARS] = { 2002, 14, 002};
    int b[YEARS] = { 01, 50, 100 };

    Wine wine_2("Test Wine", YEARS, y, b);
    wine_2.Show();

    cout << "Total bottles for " << wine_2.Label() 
        << ": " << wine_2.sum(); 

    return 0;
}