#include "drawing.h"


#include "Scene.h"

#include "PickingList.h"
#include "PickMode.h"

 
#include <glm/glm.hpp>



extern Scene scene;




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

		
			vector<Face> *faces = scene.objects[o]->groups->at(g)->faces;
			
			GLfloat * martix= &(scene.objects[o]->groups->at(g)->matrix[0][0]);

			glMultMatrixf(martix);
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
					float f = float(i) / facesNum;
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

			glPopMatrix();


		}

	}

}