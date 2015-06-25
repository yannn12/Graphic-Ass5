 
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



/*
moves camera
*/
// void moveCamera(){
//	//if (scene.CameraLocDelta.x != 0 || scene.CameraLocDelta.y != 0 || scene.CameraLocDelta.z != 0){
//
//	//	glm::vec4 forward(0.0, 0.0, -1.0, 0.0);
//	//	glm::vec4 up(0.0, 1.0, 0.0, 0.0);
//	//	glm::vec4 right(1.0, 0.0, 0.0, 0.0);
//	//	glm::mat4 curMetrix;
//	//	glGetFloatv(GL_MODELVIEW_MATRIX, &curMetrix[0][0]);
//	//	glm::vec4 forwardFinal = forward* curMetrix;
//	//	glm::vec4 upFinal = up* curMetrix;
//	//	glm::vec4 rightFinal = right* curMetrix;
//	//	glm::vec4 finalVec = forwardFinal*scene.CameraLocDelta.z + upFinal*scene.CameraLocDelta.y + rightFinal*scene.CameraLocDelta.x;
//	//	glTranslatef(finalVec[0],
//	//		finalVec[1],
//	//		finalVec[2]);
//	//	scene.CameraLocation += scene.CameraLocDelta;
//	//	scene.CameraLocDelta = zeroVec;
//	//}
//
//}


 //void rotateCameraByVector(Vector3f vec){

	//glm::vec4 sceneOrgLoc(0.0, 0.0, -100.0, 1.0);
	//glm::vec4 up(0.0, 1.0, 0.0, 0.0);
	//glm::vec4 right(1.0, 0.0, 0.0, 0.0);
	//glm::mat4 curMetrix;
	//glGetFloatv(GL_MODELVIEW_MATRIX, &curMetrix[0][0]);
	//glm::vec4 sceneFixedLoc = sceneOrgLoc*curMetrix;
	//glm::vec4 upFixed = up*curMetrix;
	//glm::vec4 rightFixed = right*curMetrix;
	//glTranslatef(sceneFixedLoc[0] * -1,
	//	sceneFixedLoc[1] * -1,
	//	sceneFixedLoc[2] * -1);

	//glRotatef((vec.x) * 180, upFixed[0], upFixed[1], upFixed[2]);
	//glRotatef((vec.y) * 180, rightFixed[0], rightFixed[1], rightFixed[2]);


	//glTranslatef(sceneFixedLoc[0],
	//	sceneFixedLoc[1],
	//	sceneFixedLoc[2]);

	// 

 //}

/*
rotates the camera
*/
// void rotateCamera(){
//	if (scene.CameraRotDelta.x != 0 || scene.CameraRotDelta.y != 0){
//		glMatrixMode(GL_PROJECTION);
//		glTranslatef(0,0,100);
//		glRotatef((scene.CameraRotDelta.x) * 180, 0, 1, 0);
//		glRotatef((scene.CameraRotDelta.y) * 180, 1, 0, 0);
//		glTranslatef(0, 0, -100);
//		scene.CameraRotDelta.x = 0;
//		scene.CameraRotDelta.y = 0;
//	
//		glMatrixMode(GL_MODELVIEW);
//
//	}
//}
/*
rotate the scene
*/
//
// void rotateScene(){
//	if (scene.SceneRotDelta.x != 0 || scene.SceneRotDelta.y != 0){
//		glm::vec4 sceneOrgLoc(0.0, 0.0, 0.0, 1.0);
//		glm::mat4 curMetrix;
//		glGetFloatv(GL_MODELVIEW_MATRIX, &curMetrix[0][0]);
//		glm::vec4 sceneFixedLoc = sceneOrgLoc*curMetrix;
//		glTranslatef(sceneFixedLoc[0] * -1,
//			sceneFixedLoc[1] * -1,
//			sceneFixedLoc[2] * -1);
//		//Vector3f totalTranslation = scene.CameraLocation + scene.SceneLocation;
//		
//		
//		//glTranslatef(-totalTranslation.x, -totalTranslation.y,-totalTranslation.z);
//		glRotatef((scene.SceneRotDelta.x) * 180, 0, 1, 0);
//		glRotatef((scene.SceneRotDelta.y) * 180, 1, 0, 0);
//		//glTranslatef(totalTranslation.x, totalTranslation.y, totalTranslation.z);
//
//		glTranslatef(sceneFixedLoc[0],
//			sceneFixedLoc[1],
//			sceneFixedLoc[2]);
//		scene.SceneRotate += scene.SceneRotDelta;
//		scene.SceneRotDelta.x = 0;
//		scene.SceneRotDelta.y = 0;
//	}
//}
//
//




 void moveScene(){

	if (scene.SceneDelta.x != 0 || scene.SceneDelta.y != 0 || scene.SceneDelta.z != 0){
		glTranslatef(scene.SceneDelta.x,
			scene.SceneDelta.y,
			scene.SceneDelta.z);
		scene.SceneLocation += scene.SceneDelta;
		scene.SceneDelta = zeroVec;
		 
	}
}


 void moveSelectedObjects(){

	/*if (scene.SelectObjLocDelta.x != 0 || scene.SelectObjLocDelta.y != 0 || scene.SelectObjLocDelta.z != 0){
		scene.selectedObjs.clear();
		scene.selectedObjs.push_back(scene.objects[0]->groups->at(4));
		scene.selectedObjs.push_back(scene.objects[0]->groups->at(10));
		for(int i=0;i<scene.selectedObjs.size();i++){
			GLfloat * martix= &(scene.selectedObjs[i]->M[0][0]);
			glm::mat4 curMetrix;
			glPushMatrix();
			glLoadIdentity();
			glMultMatrixf(martix);
		
			glTranslatef(scene.SelectObjLocDelta.x,
				scene.SelectObjLocDelta.y,
				scene.SelectObjLocDelta.z);

			glGetFloatv(GL_MODELVIEW_MATRIX, martix);
		glPopMatrix();
		}
		scene.SelectObjLocDelta = zeroVec;
	}*/
}

  void rotateSelectedObjects(){
	if (scene.SelectObjRotDelta.x != 0 || scene.SelectObjRotDelta.y != 0){
	/*	scene.selectedObjs.clear();
		scene.selectedObjs.push_back(scene.objects[0]->groups->at(4));
		scene.selectedObjs.push_back(scene.objects[0]->groups->at(10));
		Vector3f comPoint = comCalc(scene.selectedObjs);
		*/
		//glPushMatrix();
		//for(int i=0;i<scene.selectedObjs.size();i++){
		//	glm::vec4 sceneOrgLoc(comPoint.x, comPoint.y, comPoint.z, 1.0);
		//	glm::mat4 curMetrix = scene.selectedObjs[i]->M;
		//	glLoadMatrixf(&curMetrix[0][0]);
		//	//glGetFloatv(GL_MODELVIEW_MATRIX, &curMetrix[0][0]);
		//	glm::vec4 sceneFixedLoc = sceneOrgLoc*curMetrix;
		//	glTranslatef(sceneFixedLoc[0]* -1 ,
		//		sceneFixedLoc[1]* -1,
		//		sceneFixedLoc[2]* -1 );

		//	glRotatef((scene.SelectObjRotDelta.x) * 180, 0, 1, 0);
		//	glRotatef((scene.SelectObjRotDelta.y) * 180, 1, 0, 0);


		//	glTranslatef(sceneFixedLoc[0],
		//		sceneFixedLoc[1],
		//		sceneFixedLoc[2]);

		//	glGetFloatv(GL_MODELVIEW_MATRIX, &scene.selectedObjs[i]->M[0][0]);
		//}
		//scene.SelectObjRotDelta.x = 0;
		//scene.SelectObjRotDelta.y = 0;
		//glPopMatrix();
	}


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
