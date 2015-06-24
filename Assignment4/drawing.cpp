#include "drawing.h"


#include "Scene.h"
#include "MatrixHandler.h"
#include "PickingList.h"
#include "PickMode.h"

 
#include <glm/glm.hpp>



extern Scene scene;
extern PickMode pickState;



void drawAxisLines(){

	glLineWidth(LINEWIDTH);

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);

	glColor3f(0.0, 0.0, 100.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 100.0);


	glEnd();
}





void drawObj(GLenum mode){

	int objectNum = scene.objects.size();

	//glEnable(GL_LIGHTING);
	//glDisable(GL_COLOR_MATERIAL);

	


	for (size_t o = 0; o < objectNum; o++){

		int groupNum = scene.objects[o]->groups->size();
		
		if (mode == GL_SELECT)
			glLoadName(o);
		
		for (size_t g = 0; g < groupNum; g++){

			glPushMatrix();

			Group * grp = scene.objects[o]->groups->at(g);
			vector<Face> *faces = grp->faces;
			

			GLfloat orgMat[4*4];

		/*	GLfloat * martix = &(grp->matrix[0][0]);

			
			glGetFloatv(GL_MODELVIEW_MATRIX, orgMat);
			glLoadMatrixf(martix);
			glMultMatrixf(orgMat);*/
			if (!grp->scale!= 1 && grp->scale > 0){
				glScalef(grp->scale, grp->scale, grp->scale);
			}
			if (!grp->rotation.isZero()){
				glRotatef((grp->rotation.x) * 180, 0, 1, 0);
				glRotatef((grp->rotation.y) * 180, 1, 0, 0);
			}
			if (!grp->translation.isZero()){
				glTranslatef(grp->translation.x, grp->translation.y, grp->translation.z);
			}
			
			int facesNum = faces->size();
			//glPushMatrix();


			if (mode == GL_SELECT) //pushes a name to names stack
				glPushName(g);

			for (int f = 0; f < facesNum; f++){

				Face *face = &faces->at(f);
				
				glBegin(GL_POLYGON);
				for (int i = 0; i < face->normal->size(); i++){
					int n = face->normal->at(i) - 1;
					int v = face->vertice->at(i) - 1;
					//float f = float(i) / facesNum;
					//glColor3f(f, f*2, f);
					Vector3f nn = scene.normals[n];
					Vector3f vv = scene.vertices[v];
					glNormal3f(scene.normals[n].x, scene.normals[n].y, scene.normals[n].z);
					glVertex3f(scene.vertices[v].x, scene.vertices[v].y, scene.vertices[v].z);
				}
				
				glEnd();
			

				
			}
			if(mode==GL_SELECT)
				glPopName(); 
		/*	if (mode != GL_SELECT){
				
				glPopMatrix();
				glDisable(GL_LIGHTING);
				glPushMatrix();

				glTranslatef(grp->centerOfMass.x, grp->centerOfMass.y, grp->centerOfMass.z);
				glColor3f(0.3f, 0.0f, 0.0f);
				glutSolidSphere(1, 5, 5);
			 
				glPopMatrix();
				glEnable(GL_LIGHTING);
			}*/
		}


	}

	

}

void drawCom(){

		vector <Group *> * SelectedGroups;

		SelectedGroups = pickState.pickingList.getSelectedGroups();
		glClear(GL_DEPTH_BUFFER_BIT);
		glDisable(GL_LIGHTING);
		for (std::vector<Group *>::iterator it = SelectedGroups->begin(); it != SelectedGroups->end() ; ++it){
			glPushMatrix();

			Group * g = (*it);		 
		 
			glTranslatef(g->centerOfMass.x, g->centerOfMass.y, g->centerOfMass.z);
			glColor3f(1.0f, 0.0f, 0.0f);
			glutSolidSphere(0.3, 5, 5);
		
 
			glPopMatrix();
		}
		
		
	
}