#include "client.h"


using namespace std;

client::client()
{
	std::cout<<"enter surname/name/patronymic\n like this: kilin/daniil/victorovich"<<std::endl;
	std::string input;
	std::cin >> input;
			SurnameNamePatronymic = input;
	input.clear();
	std::cout <<std::endl <<"Place and date of passport issue" << std::endl;
	std::cin >> input;
			placeOfIssue = input;
	input.clear();
	std::cout << std::endl << "num of passport \n like this 1234-123456" << std::endl;
	std::cin >> input;
			passportID = input;
	input.clear();
	std::cout << std::endl << "your address" << std::endl;
	std::cin >> input;
			address = input;
	input.clear();
	std::cout << std::endl << "year of birth" << std::endl;
	int a;
	std::cin>> a;
	year = a;
	cout << "--------------------------" << endl;

	ClientPassIdToNum(passportID);
}
void client::ClientShow() {

	cout << endl << "SurnameNamePatronymic:  " << SurnameNamePatronymic;
	cout << endl << "placeOfIssue:  " << placeOfIssue;
	cout << endl << "passportID:  " << passportID;
	cout << endl << "address:  " << address;
	cout << endl << "year of birth:  " << year << endl;
	cout << "----------------------------------------------------------" << endl;
}
std::string client::GetPassId() {
	return this->passportID;
}

int client::ClientPassIdToNum(const string &PasID) {
	string CopyOfPass(PasID);
	CopyOfPass.erase(CopyOfPass.begin() + 4);// eraise 4 symb ('-')
	int num=0;
	int j = 0;
	for (int i = CopyOfPass.length()-1; i>-1; i--) {
		num=num+((int)CopyOfPass[i] -48)*pow(10,j);
		j++;
	}
	cout << "num" << num << endl;
	return num;
}

client::~client()
{
}
