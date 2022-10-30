#include "Tv.hpp"
#include "Remote.hpp"

int main()
{
	{
		try
		{
			Tv tv = Tv();
			Remote rem = Remote();
			std::cout << std::boolalpha;
			std::cout << "Is the TV on?\n>>" << tv.getMode();
			std::cout << "\nRemote mode: " << rem.getMode();
			std::cout << "Changing remote mode...\n";
			rem.changeMode(tv);
			std::cout << "Turning on the TV\n";
			tv.onOff();
			std::cout << "Changing remote mode...\n";
			rem.changeMode(tv);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "----------\n";
	{
		Tv tv = Tv(true);
		Remote rem = Remote();
		std::cout << std::boolalpha;
		std::cout << "Is the TV on?\n>>" << tv.getMode();
		std::cout << "\nRemote mode: " << rem.getMode();
		std::cout << "Changing remote mode...\n";
		rem.changeMode(tv);
	}
	{
		Tv tv = Tv(true);
		Remote rem = Remote();
		std::cout << std::boolalpha;
		std::cout << "Is the TV on?\n>>" << tv.getMode();
		std::cout << "\nRemote mode: " << rem.getMode();
		std::cout << "Changing remote mode...\n";
		rem.changeMode(tv);
		std::cout << "Again changing remote mode..\n";
		rem.changeMode(tv);
	}
	{
		Tv tv = Tv(true);
		Remote rem = Remote();
		std::cout << std::boolalpha;
		std::cout << "Is the TV on?\n>>" << tv.getMode();
		std::cout << "\nRemote mode: " << rem.getMode();
		std::cout << "Changing remote mode...\n";
		rem.changeMode(tv);
		std::cout << "Turns off the TV\n";
		tv.onOff();
		std::cout << "Is the TV on?\n>>" << tv.getMode() << std::endl;
	}
	return 0;
}