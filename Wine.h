#pragma once
#include <string>
#include <valarray>
class Wine
{
private:
	std::string label;
	int yearnum;
	std::pair<std::valarray<int>, std::valarray<int>> yearbottles;
public:
	Wine() : label(), yearbottles() {  }
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void getBottles();
	std::string& Label() { return label; }
	int sum();
	void show();
};
