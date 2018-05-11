#include "listpoint.h"


listpoint::listpoint() {
	
}
listpoint::~listpoint()
{
}

std::shared_ptr<std::vector<std::shared_ptr<listpoint>>> listpoint::GetVector(){
	return this->vectorOfPoints;
}
