#include "client.h"


using namespace std;

client::client()
{
	bool wrong = 1;
	std::cout<<"enter surname/name/patronymic\n like this: kilin/daniil/victorovich"<<std::endl;
	std::string input;
	std::cin >> input;
			SurnameNamePatronymic = input;
	input.clear();
	std::cout <<std::endl <<"Place and date of passport issue" << std::endl;
	std::cin >> input;
			placeOfIssue = input;
	input.clear();
	while (wrong) {
		std::cout << std::endl << "num of passport \n like this 1234-123456" << std::endl;
		std::cin >> input;
		if (input.length() != 11) {
			wrong = 1;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			if (((int)input[i] < 48) || ((int)input[i] > 57)) {
				wrong = 1;
				break;
			}
		}
		if (input[4] != '-') {
			wrong = 1;
			continue;
		}
		for (int i = 5; i < 11; i++) {
			if (((int)input[i] < 48) || ((int)input[i] > 57)) {
				wrong = 1;
				break;
			}
		}
		wrong = 0;
	}

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

	return num;
}

client::~client()
{
}
