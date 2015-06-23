#include "object3d.h"
#include <vector>
#include <stdio.h>

using namespace std;

Group::Group() 
{ /*
	float* martixBuff= &matrix[0][0];
	for(int d=0;d<4;d++)
		for(int l=0;l<4;l++){
			if(d==l)
				martixBuff[l*4+d]=1.0f;
			else
				martixBuff[l*4+d]=0.0f;
		}*/
}

void freeObject3d(struct object3D &obj)
{
	
	for (std::vector<Group*>::iterator it = obj.groups->begin(); it != obj.groups->end(); ++it){
		free((*it));
	}

	
	free(obj.groups);
}
