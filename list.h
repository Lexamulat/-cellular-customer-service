#pragma once
#include "listpoint.h"
class list
{
public:
	list(std::shared_ptr<BinaryTree> inpBitree, std::shared_ptr<hashtable> inptable);
	~list();
	void AddInList();
private:
	listpoint * SimHead = nullptr;
	listpoint * SimLast = nullptr;
	std::shared_ptr<BinaryTree> Bitree;
	std::shared_ptr<hashtable> table;
};

