#pragma once
#include "issuedsimcards.h"
#include <vector>
class listpoint:public issuedsimcards
{
public:
	listpoint(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table);
	~listpoint();
	std::vector<std::shared_ptr<listpoint>> GetVector();
private:
	std::vector<std::shared_ptr<listpoint>> vectorOfPoints;

};

