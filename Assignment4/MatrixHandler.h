#pragma once
 
#include "Vector3f.h"
#include "object3d.h"

 void setCamera();
 void setGlobal(); 
 void setGroupMatrix(Group &group);
 void unsetGroupMatrix();

 //void moveCamera();
 //void rotateCamera();
 //void rotateScene();
 //void moveScene();
 //void moveSelectedObjects();

 //void rotateSelectedObjects();


 Vector3f ListcomCalc(vector<Group*> &groups);
 Vector3f comCalc(Group *group);

 