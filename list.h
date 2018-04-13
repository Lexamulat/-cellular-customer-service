#pragma once
#include "listpoint.h"
#include <vector>
class list
{
public:
	list(std::shared_ptr<BinaryTree> inpBitree, std::shared_ptr<hashtable> inptable);
	~list();
	void CreateNewInList();
	void AddInList(std::shared_ptr<listpoint> temp);
	void DelFromList();
	void ShowList();
	void SortList();
	std::shared_ptr<listpoint> FindPrev(std::shared_ptr<listpoint> temp);
private:
	std::shared_ptr<listpoint> SimHead = nullptr;
	std::shared_ptr<listpoint> SimLast = nullptr;
	std::shared_ptr<BinaryTree> Bitree;
	std::shared_ptr<hashtable> table;
};

