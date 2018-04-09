#include "sim.h"



sim::sim(){
	std::cout << "enter sim number\n like this 123-1234567" << std::endl;
	std::string input;
	std::cin >> input;
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

std::string sim::GetSimNum(){

	return this->SimNum;
}
