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


bool PickingList::toggle(pick &p){

	bool found = false;
	vector<pick>::iterator pick_to_remove;
 

	for (std::vector<pick>::iterator it = this->begin(); it != this->end() && !found; ++it){
		if (it->group == p.group && it->object == p.object)
			found = true;
			pick_to_remove = it;
	}

	if (!found){
		this->push_back(p);
		object3D * obj = scene.objects.at(p.object);
		Group * group = obj->groups->at(p.group);
		selectedGroups.push_back(group);

	} else{
			
		this->erase(pick_to_remove);
		Group * grp = scene.objects.at(p.object)->groups->at(p.group);

		for (std::vector<Group *>::iterator it = selectedGroups.begin(); it != selectedGroups.end() ; ++it){
			if (*it == grp){
				selectedGroups.erase(it);
				break;
			}
		}
	 
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