#pragma once
 
#include "Vector3f.h"
#include "object3d.h"

 void setProjectionMatrix();
 void setScale();
 void moveCamera();
 void rotateCamera();
 void rotateScene();
 void moveScene();
 void moveSelectedObjects();

 Vector3f comCalc(vector<Group*> groups);
 Vector3f comCalc(Group *group);