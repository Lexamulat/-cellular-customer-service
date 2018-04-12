#include "sim.h"



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
