#pragma once
#include "issuedsimcards.h"
#include <vector>
class listpoint:public issuedsimcards
{
public:
	listpoint();
	~listpoint();
private:
	std::vector<std::shared_ptr<issuedsimcards>> vectorOfPoints;

};

