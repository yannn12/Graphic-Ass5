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


class Scene
{
public:
	 //State * state;
	 vector<Vector3f> vertices;
	 vector<Vector3f> normals;
	 vector<object3D*> objects;

	 int Buttom;


	 Vector3f SceneLocation;
	 Vector3f SceneDelta;
	 Vector3f CameraLocation;
	 
	 Vector3f CameraLocDelta;
	 Vector3f SceneRotate;
	 Vector3f SceneRotDelta;
	 Vector3f CameraRotate;
	 Vector3f CameraRotDelta;

	 float fieldOfViewAngle;
	 bool  fieldofViewChaned;

	 float scaleFactor;
	 bool scaleFactorChanged;

	Scene(void);
	~Scene(void);
};

