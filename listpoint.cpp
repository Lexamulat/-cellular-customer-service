#include "listpoint.h"



listpoint::listpoint(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table){
	issuedsimcards(Bitree,table);
}


listpoint::~listpoint()
{
}

std::vector<std::shared_ptr<listpoint>> listpoint::GetVector(){
	return this->vectorOfPoints;
}
