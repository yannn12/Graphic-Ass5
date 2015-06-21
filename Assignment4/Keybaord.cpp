#include "Keybaord.h"
#include "State.h"
#include "GlobalMode.h"
#include "CameraMode.h"
#include "glut.h"

extern State * ScaneState;
extern Scene scene;
extern GlobalMode GlobalState;
extern CameraMode CameraState;



void resetAllMatrices(){

	glMatrixMode(GL_PROJECTION); /* switch matrix mode */
	glLoadIdentity();		//load Identity matrix

	//defines view mode
	scene.fieldOfViewAngle = 60;
	gluPerspective(scene.fieldOfViewAngle, 1, 2, 200);
	glTranslatef(0, 0, -100);

	/* return to modelview mode */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	scene.scaleFactor = 1;
}

void switchState(){
	if (ScaneState == &CameraState){
		ScaneState = &GlobalState;
	}
	else{
		ScaneState = &CameraState;
	}
}


void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case ' ':
		switchState();
		break;
	case 'r':
		resetAllMatrices();
		break;


	}
}

void processSpecialKeys(int key, int xx, int yy){
	switch (key) {



	case GLUT_KEY_F2:

		if (scene.fieldOfViewAngle < 180){


			scene.fieldOfViewAngle += DELTA_CHANGE_OF_VIEW;
			scene.fieldofViewChaned = true;
		}

		break;

	case GLUT_KEY_F3:


		if (scene.fieldOfViewAngle > 0){


			scene.fieldOfViewAngle -= DELTA_CHANGE_OF_VIEW;
			scene.fieldofViewChaned = true;

		}

		break;
	case GLUT_KEY_UP:

		scene.scaleFactor *= SCALE_FACTOR;
		printf("scale factor: %f\n", scene.scaleFactor);
		break;
	case GLUT_KEY_DOWN:



		scene.scaleFactor /= SCALE_FACTOR;
		printf("scale factor: %f\n", scene.scaleFactor);
		break;
	}
}