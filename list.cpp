#include "list.h"



list::list(std::shared_ptr<BinaryTree> inpBitree, std::shared_ptr<hashtable> inptable){
	Bitree = inpBitree;
	table = inptable;
}


list::~list()
{
}

void list::CreateNewInList(){
	std::shared_ptr<listpoint> temp(new listpoint(Bitree, table));
	AddInList(temp);
}

void list::AddInList(std::shared_ptr<listpoint> temp){
	if (SimHead == nullptr) {
		SimHead = temp;
	}
	if (SimLast == nullptr) {
		SimLast = temp;
	}
	else{
		(*SimLast->GetVector())[0] = temp;
	SimLast = temp;
	}
}

void list::DelFromList(){
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
		if (FindhInTree == 1)wrong = 0;
		else wrong = 1;
	}

	std::string clientsPass = input;
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
		bool FindhInTable = table->TableSearchWithInputString(input,1,1);
		if (FindhInTable == 1)wrong = 0;
		else wrong = 1;
	}

	std::string clientsSimNum = input;

	bool b = 0;
	std::shared_ptr<listpoint> current = SimHead;
	do {
		if ((current->clientsPass == clientsPass) && (current->clientsSimNum == clientsSimNum)) {
			b = 1;
			break;
		}
		current = (*current->GetVector())[0];
	} while (current != nullptr);
	if (b = 0) {
		std::cout << "no such elem" << std::endl;
		return;
	}
	else{
		//current
	if (current == SimHead) {
		SimHead = (*current->GetVector())[0];
		if (current == SimLast) {
			SimLast = nullptr;
			return;
		}
	}
	else {
		std::shared_ptr<listpoint> Precurrent = FindPrev(current);
		if (current == SimLast) {
			SimLast = Precurrent;
		}
		(*Precurrent->GetVector())[0] = (*current->GetVector())[0];
		std::cout << "deleted" << std::endl;
	}
	}
}

void list::ShowList(){
	if (SimHead == nullptr) {
		std::cout << "list is empty" << std::endl;
		return;
	}
	
	std::cout << std::setw(15) << "Passport ID" << std::setw(15) << "Num of Sim" << std::setw(15) << "Start Date" << std::setw(15) << "End Date" << std::endl;

	std::shared_ptr<listpoint> current = SimHead;
	do {
	current->ShowMeThisInfo();
	 current = (*current->GetVector())[0];
	} while (current != nullptr);
}

void list::SortList(){
	int count = 0;
	std::shared_ptr<listpoint> current = SimHead;
	std::shared_ptr<listpoint> left = SimHead;
	std::shared_ptr<listpoint> right = SimHead;
	int j;
	do {
		count++;
		current = (*current->GetVector())[0];
	} while (current != nullptr);
	int medium = count / 2;


	while (medium>0)
	{
		for (int i = 0; i<count - medium; i++)
		{
			j = i;
			while (j >= 0 && (GetIndex(j)->clientsSimnumToInt()>GetIndex(j+medium)->clientsSimnumToInt()))
			{
				Swap(GetIndex(j), GetIndex(j + medium));
				//this->ShowList();
				j--;
			}
		}
		medium = medium / 2;
	}
	

}

void list::Swap(std::shared_ptr<listpoint> first, std::shared_ptr<listpoint> second){
	bool b = 0;
	std::shared_ptr<listpoint> fake = first;
	std::shared_ptr<listpoint> help = (*second->GetVector())[0];

	std::shared_ptr<listpoint> Prefirst = FindPrev(first);
	std::shared_ptr<listpoint> Presecond = FindPrev(second);
	if (second == SimLast) b = 1;
	if (Prefirst != first) (*Prefirst->GetVector())[0] = second;
	
	if((*first->GetVector())[0]!=second)(*second->GetVector())[0] = (*first->GetVector())[0];
	else (*second->GetVector())[0] = first;
	if(SimHead==first)SimHead = second;
	(*Presecond->GetVector())[0] = first;
	(*first->GetVector())[0] = help;
	if (b == 1) {
		SimLast = first;

	}
}

std::shared_ptr<listpoint> list::GetIndex(int index)
{
	if (index == 0)return SimHead;
	std::shared_ptr<listpoint> current = SimHead;
	for (int i = 0; i < index; i++) {
		current = (*current->GetVector())[0];
	}
	return current;
}

std::shared_ptr<listpoint> list::FindPrev(std::shared_ptr<listpoint> temp){
	std::shared_ptr<listpoint> Precurrent = SimHead;
	if (temp == SimHead) {
		return temp;
	}
	while ((*Precurrent->GetVector())[0] != temp) {
		Precurrent = (*Precurrent->GetVector())[0];
	}
	return Precurrent;
}

void list::TestData(){
	std::string clientsPass="1919-458333";
	std::string clientsSimNum = "123-1234567";
	std::string startDate="1";
	std::string endDate="2";
	std::shared_ptr<listpoint> temp(new listpoint(Bitree, table, clientsPass, clientsSimNum, startDate, endDate));
	AddInList(temp);

	clientsPass = "1245-458333";
	clientsSimNum = "111-1111111";
	startDate = "4";
	endDate = "5";
	std::shared_ptr<listpoint> temp1(new listpoint(Bitree, table, clientsPass, clientsSimNum, startDate, endDate));
	AddInList(temp1);

	clientsPass = "1245-458333";
	clientsSimNum = "121-1122111";
	startDate = "7";
	endDate = "8";
	std::shared_ptr<listpoint> temp2(new listpoint(Bitree, table, clientsPass, clientsSimNum, startDate, endDate));
	AddInList(temp2);
}

void list::MakeLayers(){

	if (SimHead == nullptr) {
		std::cout << "list is empty" << std::endl;
		return;
	}
	std::shared_ptr<listpoint> current = SimHead;
	do {
		if ((*current->GetVector()).size() > 1) {
			(*current->GetVector()).erase((*current->GetVector()).begin() + 1);
		}
		current = (*current->GetVector())[0];
	} while (current != nullptr);


	std::shared_ptr<listpoint> mas[2]{ nullptr,nullptr };
	do {
		if ((((current->clientsSimnumToInt()) / 1000000000) == 4) && (mas[0] == nullptr))mas[0] = current;
		if ((((current->clientsSimnumToInt()) / 1000000000) == 8) && (mas[1] == nullptr)) {
			mas[1] = current;
			break;
		}
		current = (*current->GetVector())[0];
	} while (current != nullptr);

	
	(*SimHead->GetVector()).push_back(mas[0]);
	(*mas[0]->GetVector()).push_back(mas[1]);

}

void list::Search() {
	std::string sim;
	std::cout << "enter sim number\n like this 123-1234567" << std::endl;
	std::cin >> sim;
	std::string copysim = sim;
	copysim.erase(copysim.begin() + 3);
	int num = 0;
	int check = 0;
	bool detected = 0;
	int j = 0;
	for (int i = copysim.length() - 1; i > -1; i--) {
		num = num + ((int)copysim[i] - 48)*pow(10, j);
		j++;
	}
	int step = num / 1000000000;

	std::shared_ptr<listpoint> current = SimHead;

	if (step >= 4) {
		current = (*SimHead->GetVector())[1];
	if(step>=8)current = (*current->GetVector())[1];
	}
	do {
		for (int i = 0; i < sim.length(); i++) {
			if (sim[i] == current->clientsSimNum[i]) {
				check++;
			}
		}
		if (check == 11) current->ShowMeThisInfo();
		check = 0;
		current = (*current->GetVector())[0];
	} while (current != nullptr);
	
	

}
