#pragma once
#include<string>
#include <iostream>
#include <iomanip>
class sim
{
public:
	sim(std::string iSimNum, std::string irate, int iYearOfIssue);
	sim();
	~sim();
	void ShowSim();
	std::string GetSimNum();
	void SetSimNum();
	bool CompareInputStringWithThisRate(std::string input);
	void ShowMeThisSimInfo();
	//std::string Getrate();
	//int Getyear();
	bool Gethave();
	void Sethave(bool sethave);
private:
	std::string SimNum;
	std::string rate;
	int YearOfIssue;
	bool have=1;
};

