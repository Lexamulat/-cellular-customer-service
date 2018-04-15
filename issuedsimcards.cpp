#include "issuedsimcards.h"



issuedsimcards::issuedsimcards(){
	//std::cout << std::endl << "num of passport \n like this 1234-123456" << std::endl;
}

issuedsimcards::issuedsimcards(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table, std::string iclientsPass, std::string iclientsSimNum, std::string istartDate, std::string iendDate){

	clientsPass = iclientsPass;
	clientsSimNum = iclientsSimNum;
	startDate = istartDate;
	endDate = iendDate;
}

issuedsimcards::issuedsimcards(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table){
	bool wrong = 1;
	std::string input;
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
		bool FindhInTree = Bitree->Search(input);
		if(FindhInTree==1)wrong = 0;
		else wrong = 1;
	}

	clientsPass = input;
	wrong = 1;
	input.clear();
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
		bool FindhInTable = table->TableSearchWithInputString(input);
		if (FindhInTable == 1)wrong = 0;
		else wrong = 1;
	}

	clientsSimNum = input;
	input.clear();

	std::cout << "enter start date" << std::endl;
	std::cin >> input;
	startDate = input;
	input.clear();

	std::cout << "enter end date" << std::endl;
	std::cin >> input;
	endDate = input;

}


issuedsimcards::~issuedsimcards()
{
}

void issuedsimcards::ShowMeThisInfo(){
	std::cout << this->clientsPass << "|" << this->clientsSimNum << "|" << this->startDate << "-" << this->endDate << std::endl;
}

int issuedsimcards::clientsSimnumToInt(){
	std::string fake = this->clientsSimNum;
	fake.erase(fake.begin() + 3);// eraise 3 symb ('-')
	int num = 0;
	int j = 0;
	for (int i = fake.length() - 1; i>-1; i--) {
		num = num + ((int)fake[i] - 48)*pow(10, j);
		j++;
	}
	return num;
}
