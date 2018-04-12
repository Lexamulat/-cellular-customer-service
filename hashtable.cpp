#include "hashtable.h"



hashtable::hashtable()
{
}


hashtable::~hashtable()
{
}

bool hashtable::IsTableFull(){
	
	for (int i = 0; i < 4; i++) {
		if ((mas[i] == nullptr) || (mas[i]->GetSimNum() == "000-0000000")) {
			return false;
		}
	}
	std::cout << "The table is full" << std::endl;
	return true;
}

void hashtable::DelfromTable(){
	std::cout << "enter sim number\n like this 123-1234567" << std::endl;
	std::string input;
	std::cin >> input;
	bool CallFromDel = 1;
	tablesearch(CallFromDel);
}

void hashtable::tablesearch(bool CallFromDel){
	
	std::string input;
		std::cout << "enter sim number\n like this 123-1234567" << std::endl;
		
		std::cin >> input;

	int hashnum = hashFunc(input);
	int firsthash = hashnum;
	int count=0;
	while (true) {
		if (mas[hashnum] == nullptr) {
			std::cout << "there is no sim with such number" << std::endl;
			return;
		}
		else {
			std::string current = mas[hashnum]->GetSimNum();
			for (int i = 0; i < 11; i++) {
				if (current[i] == input[i])
					count++;
			}
			if (count==11) {
				std::cout << "detected number" << std::endl;
				mas[hashnum]->ShowSim();
				if (CallFromDel == 1) {
					mas[hashnum]->SetSimNum();
					std::cout << "deleted" << std::endl;
				}
				return;
			}
			else {
				if (hashnum == firsthash - 1) {
					std::cout << "there is no sim with such number" << std::endl;
					return;
				}
				else {
					count = 0;
					if (hashnum == 3) {
						hashnum = 0;
					}
					else hashnum++;
				}
				
			}
		}

	}
}



void hashtable::show(){
	for (int i = 0; i < 4; i++){
		if ((mas[i] == nullptr) || (mas[i]->GetSimNum() == "000-0000000")) {
			std::cout << "mas[" << i << "]-0" << std::endl;
		}
		else {
			std::cout << "mas[" << i << "]-"<< mas[i]->GetSimNum() << std::endl;
		}
	}
}

int hashtable::hashFunc(std::string simnum)
{
	int hashnum = 0;
	for (int i = 0; i < 3; i++) {
		hashnum = hashnum + (int)simnum[i];
	}
	return (hashnum)%3;
}

void hashtable::preAdd(){
	bool full=IsTableFull();
	if (full) return;
	std::shared_ptr<sim> temp(new sim());
	addInTable(temp);
}

bool hashtable::TableSearchWithInputString(std::string input){
	int hashnum = hashFunc(input);
	int firsthash = hashnum;
	int count = 0;
	while (true) {
		if (mas[hashnum] == nullptr) {
			std::cout << "there is no sim with such number" << std::endl;
			return 0;
		}
		else {
			std::string current = mas[hashnum]->GetSimNum();
			for (int i = 0; i < 11; i++) {
				if (current[i] == input[i])
					count++;
			}
			if (count == 11) {
				if (mas[hashnum]->Gethave()==1) {
					return 1;
				}
				else {
					std::cout <<"SIM card is not available" << std::endl;
					return 0;
				}
			}
			else {
				if (hashnum == firsthash - 1) {
					std::cout << "there is no sim with such number" << std::endl;
					return 0;
				}
				else {
					count = 0;
					if (hashnum == 3) {
						hashnum = 0;
					}
					else hashnum++;
				}

			}
		}

	}
}

void hashtable::addInTable(std::shared_ptr<sim> obj){
	int hashnum=hashFunc(obj->GetSimNum());
	bool f = 1;
	while (f) {
		if ((mas[hashnum] == nullptr) || (mas[hashnum]->GetSimNum() == "000-0000000")) {
			mas[hashnum] = obj;
			f = 0;
		}
		else {
			hashnum++;
		}
	}
	
}

void hashtable::TestDataForTable(){

	std::string SimNum = "123-1234567";
	std::string rate = "безлимитище";
	int YearOfIssue = 10;
	std::shared_ptr<sim> temp(new sim(SimNum,rate,YearOfIssue));
	addInTable(temp);


	 SimNum = "111-1111111";
	 rate = "smart";
	 YearOfIssue = 20;

	std::shared_ptr<sim> temp1(new sim(SimNum, rate, YearOfIssue));
	addInTable(temp1);

	SimNum = "121-1122111";
	rate = "lite";
	YearOfIssue = 30;

	std::shared_ptr<sim> temp2(new sim(SimNum, rate, YearOfIssue));
	addInTable(temp2);

}
