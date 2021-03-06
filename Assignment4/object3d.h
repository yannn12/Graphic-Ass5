#pragma once

 
#include <vector>
#include "Vector3f.h"

using namespace std;

#include <glm/glm.hpp>

typedef struct Face{
	vector<int>  *vertice;
	vector<int>  *normal;
};

class Group{
public:
	int name;
	glm::mat4  matrix;
	vector<Face> *faces;
	Vector3f centerOfMass;
	Vector3f rotation, translation;
	float scale;
//	Group();

};

typedef struct Point{

	int x;
	int y;
};


struct object3D
{
public:

	int name;
	vector<Group*> *groups;

};

void freeObject3d(struct object3D &obj);


