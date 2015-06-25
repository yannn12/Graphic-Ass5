#pragma once

#include "object3d.h"
#include "vector3f.h"

#include <vector>
 
typedef  unsigned int uint;


struct pick  {
	uint object;
	uint group;
	
};
class PickingList:
	public std::vector<pick>
{
public:
	/* 
	 
	if the  (object + group) key  of the pick exist , it is removed  from the list  and the function  return false
	else the pick is added to the list and the function return true
	*/ 
	bool toggle(pick &p);
	
	vector <Group *> * getSelectedGroups();
	Vector3f centerOfmass;

	void clacCenterOfmass();
	void clearPick();
 
	PickingList();
	~PickingList();

private : 
	vector <Group *> selectedGroups;
	 
};



