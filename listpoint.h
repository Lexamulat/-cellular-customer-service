#pragma once
#include "issuedsimcards.h"
#include <vector>
class listpoint:public issuedsimcards
{
public:
	listpoint();
	listpoint(std::shared_ptr<BinaryTree> Bitree, std::shared_ptr<hashtable> table) :issuedsimcards(Bitree, table) {
		vectorOfPoints->insert(vectorOfPoints->end(), nullptr);
	};
	
	~listpoint();
	std::shared_ptr<std::vector<std::shared_ptr<listpoint>>> GetVector();
private:
	std::vector<std::shared_ptr<listpoint>> array;
	std::shared_ptr<std::vector<std::shared_ptr<listpoint>>> vectorOfPoints = std::make_shared<std::vector<std::shared_ptr<listpoint>> >(std::move(array));
};

