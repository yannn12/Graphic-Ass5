
#include "PickMode.h"
#include "PickingList.h"
#include "drawing.h"
#include "RotationPickMode.h"
#include "ScalePickMode.h"
#include "TranslationPickMode.h"


#define PICK_BUFSIZE 512

extern State * ScaneState;
extern RotationPickMode RotationPickState;
extern TranslationPickMode TranslationPickState;
extern ScalePickMode ScalePickState;


void startPicking(GLuint *selectionBuf)
{
	glSelectBuffer(PICK_BUFSIZE, selectionBuf); //declare buffer for input in selection mode
	glRenderMode(GL_SELECT); //change to selecting mode
	glInitNames();			//initialize names stack
	glPushName(-1);			//push name
}


void PickMode::processHits(GLint hits, GLuint *buffer, float *zValue)
{

	float z1, z2;
	pick pick;

	if (buffer[0] > 0){
	 
		float closet = 4294967295.0f;
		for (int i = 0; buffer[i]>0; i += 3 + buffer[i])
		{
			if (buffer[i + 1] < closet){

				pick.object = buffer[i + 3];
				pick.group = buffer[i + 4];
				closet = buffer[i + 1];
			}
		}

		if (pickingList.toggle(pick)){
			printf("added pick:  Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}
		else {
			printf("remove pick: Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}

	}
}

void PickMode::mouse(int button, int state, int x, int y){

	GLint viewport[4];
	//float pix[4];
	GLuint selectionBuf[PICK_BUFSIZE];

	for (int i = 0; i<PICK_BUFSIZE; i++)
	{
		selectionBuf[i] = 0;
	}
	glGetIntegerv(GL_VIEWPORT, viewport); //reading viewport parameters
	press = !press;


	if (press && button == GLUT_RIGHT_BUTTON)

	{   //use selection mode to pick

		//glReadPixels(x, viewport[3] - y, 1, 1, GL_RGBA, GL_FLOAT, pix);
		glMatrixMode(GL_PROJECTION);
		glReadPixels((GLdouble)x, (GLdouble)viewport[3] - y, 2, 2, GL_DEPTH_COMPONENT, GL_FLOAT, zValue);

		glPushMatrix();	//saves current projection matrix
		glLoadIdentity();

		startPicking(selectionBuf); //preper selection mode

		gluPickMatrix((GLdouble)x, (GLdouble)viewport[3] - y, 1, 1, viewport); //change matrices so only the area of the picking pixel can be seen.

		//gluPerspective(scene.camera.fieldOfViewAngle, 1, 2, 200);//return to perspective state 
		//glTranslatef(0, 0, -100);

		gluPerspective(scene.camera.fieldOfViewAngle, 1, 2, 200);


		glRotatef(scene.camera.Rotation.x, 0, 1, 0);
		glRotatef(scene.camera.Rotation.y, 1, 0, 0);

		glTranslatef(scene.camera.Translation.x, scene.camera.Translation.y, scene.camera.Translation.z);


		/**************/
		glMatrixMode(GL_MODELVIEW);
		drawObj(GL_SELECT); //draws board on background


		int hits = glRenderMode(GL_RENDER); //gets hits number 

		glMatrixMode(GL_PROJECTION);
		glPopMatrix(); //restores projection matrix

		glMatrixMode(GL_MODELVIEW);
		processHits(hits, selectionBuf, zValue); //check hits

	 
	}
	if (press && button == GLUT_LEFT_BUTTON){
		printf("Done picking. ");
		switch (mode){

		case ROTATE:
			printf("Entering rotate mode.\n");
			pickingList.clacCenterOfmass();
			ScaneState = &RotationPickState;
			
			break;
		case SCALE:
			printf("Entering scale mode.\n");
			pickingList.clacCenterOfmass();
			ScaneState = &ScalePickState;
			break;
		case TRANSLATE:
			printf("Entering translate mode.\n");
			pickingList.clacCenterOfmass();
			ScaneState = &TranslationPickState;
			break;
		}
	}

}
void PickMode::mouseMotion(int x, int y){

}



void PickMode::processNormalKeys(unsigned char key, int x, int y){

}

void PickMode::processSpecialKeys(int key, int xx, int yy){
}



PickMode::PickMode(Scene& scene) :State(scene)
{
	press = false;
 

}


PickMode::~PickMode(void)
{
}


void PickMode::setMode(Mode mode){
	this->mode = mode;
}