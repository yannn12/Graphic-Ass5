#pragma once


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
	add a uniqe pick. e.g only one entry for (object + group) key;
	if the  (object + group) key  of the pick exist  nothing happens and the function return false, else the pick is
	added and the function return true
	*/ 
	bool add(pick &p);
	PickingList();
	~PickingList();
};

