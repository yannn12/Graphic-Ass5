#pragma once
#include <string>
#include "Vector3f.h"
#include "glut.h"
#include <vector>
#include "object3d.h"

using namespace std;

#define W_WIDTH 512

#define W_HEIGHT 512



 

typedef struct Vector2f{ 
	float x;
	float y;

	Vector2f(float xVal,float yVal){x = xVal; y = yVal;}
};


typedef struct Camera{

	 
	Vector3f Translation;
	Vector3f Rotation;
	float fieldOfViewAngle;


};

typedef struct Global{


	Vector3f Translation;
	Vector3f Rotation;
	float scale;
	 


};



class Scene
{
public:
	 //State * state;
	 vector<Vector3f> vertices;
	 vector<Vector3f> normals;
	 vector<object3D*> objects;

	/* vector<Group*> selectedObjs;*/

	 Camera camera;
	 Global global;

 

	 void reset();

	Scene(void);
	~Scene(void);
};

