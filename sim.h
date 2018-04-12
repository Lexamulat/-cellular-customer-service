#pragma once
#include<string>
#include <iostream>
class sim
{
public:
	sim(std::string iSimNum, std::string irate, int iYearOfIssue);
	sim();
	~sim();
	void ShowSim();
	std::string GetSimNum();
	void SetSimNum();
	
	//std::string Getrate();
	//int Getyear();
	bool Gethave();
private:
	std::string SimNum;
	std::string rate;
	int YearOfIssue;
	bool have=1;
};

