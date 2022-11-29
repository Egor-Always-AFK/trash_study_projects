#include "incl/MainHeader.h"

int main()
{
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
				fileInput();
				break;

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