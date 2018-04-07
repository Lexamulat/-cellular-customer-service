#pragma once
#include<string>
#include <iostream>
#include <cmath>
class client
{
public:
    client();



	void ClientShow();
	int ClientPassIdToNum(const std::string &PasID);
	std::string GetPassId();

	~client();
private:

	std::string passportID;
	std::string placeOfIssue;
	std::string SurnameNamePatronymic;
	int year;
	std::string address;



};

