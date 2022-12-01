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
			{
				if (vec.size() != 0)
				{
					std::vector<AutoService> tmp = manualInput();
					vec = addVectorAtVector(vec, tmp);
				}
				else
					vec = manualInput();
				break;
			}
			case FILEINPUT:
			{
				if (vec.size() != 0)
				{
					std::vector<AutoService> tmp = fileInput();
					vec = addVectorAtVector(vec, tmp);
				}
				else
					vec	= fileInput();
				break;
			}
			case FILEOUTPUT:
				fileOutput(vec);
				break;
			case OUTPUT:
			{
				if (vec.size() != 0)
					output(vec);
				else
					std::cout << "Size of vector = 0\n";
				break;
			}
			case SORT:
				vec = sort(vec);
				break;

			case SEARCH:
				search(vec);
				break;

			case EDIT:
				vec = edit(vec);
				break;

			case EXIT:
				exit(0);
			default:
				std::cout << "hi i'm here\n";
				break;
			}
		
	}
}