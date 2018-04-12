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
	//SimLast->GetVector()->insert(SimLast->GetVector()->end(), temp);
	SimLast = temp;
	}
}

void list::ShowList(){
	std::shared_ptr<listpoint> current = SimHead;
	//current->ShowMeThisInfo();
	do {
	current->ShowMeThisInfo();
	 current = (*current->GetVector())[0];
	} while (current != nullptr);
}
