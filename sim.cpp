#include "sim.h"



sim::sim(std::string iSimNum, std::string irate, int iYearOfIssue){
	SimNum = iSimNum;
	rate = irate;
	YearOfIssue = iYearOfIssue;
}

sim::sim(){
	bool wrong = 1;
	std::string input;
	while (wrong) {
		std::cout << "enter sim number\n like this 123-1234567" << std::endl;
		std::cin >> input;
		if (input.length() != 11) {
			wrong = 1;
			continue;
		}
		for (int i = 0; i < 3; i++) {
			if (((int)input[i] < 48) || ((int)input[i] > 57)) {
				wrong = 1;
				break;
			}
		}
		if (input[3] != '-') {
			wrong = 1;
			continue;
		}
		for (int i = 4; i < 11; i++) {
			if (((int)input[i] < 48) || ((int)input[i] > 57)) {
				wrong = 1;
				break;
			}
		}
		wrong = 0;
	}
	SimNum = input;
	input.clear();
	std::cout << std::endl << "rate of this sim?" << std::endl;
	std::cin >> input;
	rate = input;
	std::cout << std::endl << "YearOfIssue" << std::endl;
	int a;
	std::cin >> a;
	YearOfIssue = a;
}


sim::~sim()
{
}

void sim::ShowSim(){
	std::cout << "sim number : " << std::endl;
	std::cout <<this->SimNum;

	std::cout << std::endl << "rate of this sim : " << std::endl;
	std::cout << this->rate;

	std::cout << std::endl << "YearOfIssue : " << std::endl;
	std::cout <<this->YearOfIssue;

	std::cout << std::endl << "avaliable : " << std::endl;
	std::cout <<this->have;
}
std::string sim::GetSimNum(){

	return this->SimNum;
}

void sim::SetSimNum()
{
	this->SimNum = "000-0000000";
}

bool sim::CompareInputStringWithThisRate(std::string input){
	if (input.length() != rate.length()) return false;
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != rate[i]) return false;
	}

	return true;
}

void sim::ShowMeThisSimInfo(){

	std::cout << std::setw(15) << this->SimNum << std::setw(20) << this->rate << std::setw(20) << this->YearOfIssue << std::setw(15) << this->have << std::endl;
}

//std::string sim::Getrate()
//{
//	return this->rate;
//}
//
//int sim::Getyear()
//{
//	return 0;
//}
//
bool sim::Gethave()
{
	if (this->have == 1)return 1;
	return false;
}

void sim::Sethave(bool sethave){
	this->have = sethave;
}
