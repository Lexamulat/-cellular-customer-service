#pragma once
#include<string>
#include "BinaryTree.h"
#include "hashtable.h"
class issuedsimcards
{
public:
	issuedsimcards(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table);
	~issuedsimcards();
private:
	std::string clientsPass;
	std::string clientsSimNum;
	std::string startDate;
	std::string endDate;
};

