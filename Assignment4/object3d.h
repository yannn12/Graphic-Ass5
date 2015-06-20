#pragma once

 
#include <vector>
using namespace std;



typedef struct Face{
	vector<int>  *vertice;
	vector<int>  *normal;
};

typedef struct Group{

	int name;
	vector<Face> *faces;
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


