#include "incl/Employee.hpp"
#include "incl/Fink.hpp"
#include "incl/Highfink.hpp"
#include "incl/Manager.hpp"

int main()
{
	std::cout << "-----MANAGER TEST-----\n";
	{
		std::cout << "Test #1";
		Manager man = Manager();
		man.ShowAll();
		man.SetAll();
		man.ShowAll();
	}
	{
		std::cout << "\n\nTest #2";
		Manager man = Manager("John", "Snow", "Warrior", 21);
		man.ShowAll();
	}
	std::cout << "\n-----HIGHFINK TEST-----\n";
	{
		std::cout << "\n\nTest #3";
		Highfink hf = Highfink();
		hf.ShowAll();
		hf.SetAll();
		hf.ShowAll();
	}
	{
		std::cout << "\n\nTest #4";
		Highfink hf = Highfink("Bob", "Ross", "Writer", "Report", 10);
		hf.ShowAll();
	}
	{
		std::cout << "\n\nTest #5";
		Manager man = Manager("John", "Snow", "Warrior", 42);
		Highfink hf = Highfink(man, "Report2");
		hf.ShowAll();
	}
	std::cout << std::endl;
	return 0;
}