#include "Wine.h"

#include <cstring>
#include <iostream>
#include <vector>

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	label = std::string(l);
	yearnum = y;
	yearbottles = std::make_pair(*yr, *bot);
}


Wine::Wine(const char* l, int y)
{
	label = std::string(l);
	yearnum = y;
	yearbottles = std::make_pair(*(new int[y]), *(new int[y]));
}


void Wine::getBottles()
{
	std::cout << "Enter the years:\n";
	std::vector<int> f;
	f.resize(yearnum);
	for (int i = 0; i < yearnum; i++)
	{
		std::cout << "Enter year " << i + 1 << ": ";
		std::cin >> f[i];
	}
	yearbottles.first = std::valarray<int>(f.data(), f.size());

	std::cout << "Enter the amount of bottles for each year:\n";
	std::vector<int> g;
	g.resize(yearnum);
	for (int i = 0; i < yearnum; i++)
	{
		std::cout << "Enter the amount of bottles for " << yearbottles.first[i] << ": ";
		std::cin >> g[i];
	}
	yearbottles.second = std::valarray<int>(g.data(), g.size());
}


int Wine::sum()
{
	int sum{};
	for (int count : yearbottles.second)
		sum += count;
	return sum;
}


void Wine::show()
{
	std::cout << "Wine: " << label << "\n"
		<< "\tYear\tBottles\n";
	for (int i = 0; i < yearbottles.first.size(); i++)
		std::cout << "\t" << yearbottles.first[i] << "\t" << yearbottles.second[i] << "\n";
}
