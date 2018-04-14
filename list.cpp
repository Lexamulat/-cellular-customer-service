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
		bool FindhInTable = table->TableSearchWithInputString(input);
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

void list::ShowList(){
	if (SimHead == nullptr) {
		std::cout << "list is empty" << std::endl;
		return;
	}
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
	SimHead = second;
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
