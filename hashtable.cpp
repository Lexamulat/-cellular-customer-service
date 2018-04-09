#include "hashtable.h"



hashtable::hashtable()
{
}


hashtable::~hashtable()
{
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
	std::shared_ptr<sim> temp(new sim());
	addInTable(temp);
}

void hashtable::addInTable(std::shared_ptr<sim> obj){
	int hashnum=hashFunc(obj->GetSimNum());
	mas[hashnum] = obj;
	std::cout<<mas[hashnum]->GetSimNum();
	if (mas[0] == nullptr) std::cout << "nul";
	
}
