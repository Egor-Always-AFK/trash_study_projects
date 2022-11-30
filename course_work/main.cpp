#include "incl/MainHeader.h"

int main()
{
	std::vector<AutoService> vec;
	while (1)
	{
		menu();
		std::cout << "Enter ur path:\n>>";
		int choice;
		std::cin >> choice;
			switch (choice)
			{
			case INPUT:
				
				break;
			case FILEINPUT:
				vec	= fileInput();
				break;

			case FILEOUTPUT:

				break;
			case OUTPUT:
			{
				std::size_t i = 0;
				std::vector<AutoService>::iterator vec_begin = vec.begin();
				while (i != vec.size())
				{
					std::cout << *(vec_begin) << "\n";
					i++;
					vec_begin++;
				}
				break;
			}
			case SORT:

				break;

			case SEARCH:
			
				break;

			case EDIT:

				break;

			case EXIT:
				exit(0);
			default:
				std::cout << "hi i'm here\n";
				break;
			}
		
	}
}