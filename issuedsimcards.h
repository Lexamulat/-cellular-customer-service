#pragma once
#include<string>
#include "BinaryTree.h"
#include "hashtable.h"
class issuedsimcards
{
public:
	issuedsimcards();
	issuedsimcards(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table, std::string iclientsPass,std::string iclientsSimNum,	std::string istartDate,std::string iendDate);
	issuedsimcards(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table);
	~issuedsimcards();
	void ShowMeThisInfo();
	int clientsSimnumToInt();
//private:
	std::string clientsPass;
	std::string clientsSimNum;
	std::string startDate;
	std::string endDate;
};

