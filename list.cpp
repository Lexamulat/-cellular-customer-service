#include "list.h"



list::list(std::shared_ptr<BinaryTree> inpBitree, std::shared_ptr<hashtable> inptable){
	Bitree = inpBitree;
	table = inptable;
}


list::~list()
{
}

void list::AddInList(){
	std::shared_ptr<issuedsimcards> temp(new issuedsimcards());
}
