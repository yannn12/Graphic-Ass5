#include "PickingList.h"
#include "Scene.h"
#include <vector>


extern Scene scene;

using namespace std;
 
PickingList::PickingList(){
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
		object3D * obj= scene.objects.at(p.object);
		Group * group= obj->groups->at(p.group);
		selectedGroups.push_back(group);
	}
	return !found;
}

vector <Group *> * PickingList::getSelectedGroups() {

	return &selectedGroups;
}

void PickingList::clearPick(){
	this->clear();
	selectedGroups.clear();

}