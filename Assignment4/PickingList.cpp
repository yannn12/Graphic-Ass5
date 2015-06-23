#include "PickingList.h"
#include <vector>

using namespace std;

PickingList::PickingList()
{
}


PickingList::~PickingList()
{
}


bool PickingList::add(pick &p){

	bool found = false;
	for (std::vector<pick>::iterator it = this->begin(); it != this->end() && !found; ++it){
		if (it->group == p.group && it->object == p.object)
			found = true;
	}

	if (!found){
		this->push_back(p);
	}
	return !found;
}