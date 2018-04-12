#include "listpoint.h"


listpoint::listpoint() {
	
}

//listpoint::listpoint(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table){
//	issuedsimcards::issuedsimcards(Bitree,table);
//	std::cout << "r";
//	vectorOfPoints->insert(vectorOfPoints->end(),nullptr);
//
//}





listpoint::~listpoint()
{
}

std::shared_ptr<std::vector<std::shared_ptr<listpoint>>> listpoint::GetVector(){
	return this->vectorOfPoints;
}
