#include <iostream>
#include <string>

#include "Wine.h"

char err[29] = "Please enter a valid option\n";

void showMenu();

void wineCaller();

int main()
{
	
	std::string in;
	int c;

	showMenu();

	while (std::cin >> in)
	{
		if (in == "q" || in == "Q")
			return 0;

		if (in.length() > 1)
		{
			std::cout << err;
			showMenu();
			continue;
		}

		c = atoi(in.c_str());

		switch (c)
		{
		case 0: wineCaller(); break;
		default: std::cout << err;
		}

		showMenu();
	}
	return 0;
}


void showMenu()
{
	std::cout << "0) Wine\nq) Quit\n> ";
}


void wineCaller()
{
	std::cin.clear();
	std::cin.ignore(100, '\n');
	std::cout << "Enter the name of the wine: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Enter the amount of vintage years: ";
	int years;
	std::cin >> years;

	Wine w(name.c_str(), years);
	w.getBottles();
	w.show();
	std::cout << "Total bottles for " << w.Label() << ": " << w.sum() << "\n";

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.show();
	std::cout << "Total bottles for " << more.Label() << ": "
		<< more.sum() << "\n";
}
