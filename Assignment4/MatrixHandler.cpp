 
#include "MatrixHandler.h"
#include "Scene.h"
#include "Vector3f.h"
#include "object3d.h"
#include "PickingList.h"


 
#include <glm/glm.hpp>
 
extern Scene scene;

static Vector3f zeroVec(0, 0, 0);
 

/*
*
*	 
*
*/
void setCamera() {

	 

		glMatrixMode(GL_PROJECTION); /* switch matrix mode */
		glLoadIdentity();		//load Identity matrix
		
		gluPerspective(scene.camera.fieldOfViewAngle, 1, 2, 200);
		

		glRotatef(scene.camera.Rotation.x, 0, 1, 0);
		glRotatef(scene.camera.Rotation.y, 1, 0, 0);

		glTranslatef(scene.camera.Translation.x, scene.camera.Translation.y, scene.camera.Translation.z);

		glMatrixMode(GL_MODELVIEW);
	 
	 
}
 



 
void setGlobal(){



	glMatrixMode(GL_MODELVIEW); /* switch matrix mode */
	glLoadIdentity();		//load Identity matrix

	glTranslatef(scene.global.Translation.x, scene.global.Translation.y, scene.global.Translation.z);
	glRotatef(scene.global.Rotation.x, 0, 1, 0);
	glRotatef(scene.global.Rotation.y, 1, 0, 0);
	glScalef(scene.global.scale, scene.global.scale, scene.global.scale);

	 
	

}

 void setGroupMatrix(Group &group){
		
	glPushMatrix();
	glMultMatrixf(&(group.M[0][0]));
}

 void unsetGroupMatrix(){
	glPopMatrix();
}




  Vector3f ListcomCalc(vector<Group*> &groups){

	 
	 Vector3f result(0, 0, 0);
	 int verCount=0;
	 for(int i=0;i<groups.size();i++){
		 
		  

		 for(int j=0;j<groups[i]->faces->size();j++){
			
			 for(int k=0;k<groups[i]->faces->at(j).vertice->size();k++){
				 verCount++;
				 int verInd = groups[i]->faces->at(j).vertice->at(k)-1;
				 Vector3f *vertix = &scene.vertices[verInd];

				 result.x += vertix->x;
				 result.y += vertix->y;
				 result.z += vertix->z;
			 }
		 }
		 
	 }
	 if (verCount != 0){
		 result.x /= verCount;
		 result.y /= verCount;
		 result.z /= verCount;
	 }
	 return result;

 }


 Vector3f comCalc(Group *group){
	 Vector3f result(0, 0, 0);
	 int verCount = 0;
	 
	 for (int j = 0; j < group->faces->size(); j++){
		 for (int k = 0; k < group->faces->at(j).vertice->size(); k++){
			 verCount++;
			 int verInd = group->faces->at(j).vertice->at(k) - 1;
			 Vector3f vertix = scene.vertices[verInd];
			 result.x += vertix.x;
			 result.y += vertix.y;
			 result.z += vertix.z;
		 }
	 }
 
 
	 result.x /= verCount;
	 result.y /= verCount;
	 result.z /= verCount;

	 return result;

 }
