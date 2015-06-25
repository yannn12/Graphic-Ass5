#include "object3d.h"
#include <vector>
#include <stdio.h>

using namespace std;

Group::Group() : M()
{  
	 
}
Group::~Group(){

}

void freeObject3d(struct object3D &obj)
{
	
	for (std::vector<Group*>::iterator it = obj.groups->begin(); it != obj.groups->end(); ++it){
		free((*it));
	}

	
	free(obj.groups);
}
