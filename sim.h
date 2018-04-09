#pragma once
#include<string>
#include <iostream>
class sim
{
public:
	sim();
	~sim();
	std::string GetSimNum();
private:
	std::string SimNum;
	std::string rate;
	int YearOfIssue;
	bool have=1;
};

