#include "Keybaord.h"
#include "State.h"
#include "GlobalMode.h"
#include "CameraMode.h"
#include "PickMode.h"
#include "glut.h"
#include "RotationPickMode.h"
#include "ScalePickMode.h"
#include "TranslationPickMode.h"

extern State * ScaneState;
extern Scene scene;
extern GlobalMode GlobalState;
extern CameraMode CameraState;
extern RotationPickMode RotationPickState;
extern TranslationPickMode TranslationPickState;
extern ScalePickMode ScalePickState;
extern PickMode pickState;


void resetAllMatrices(){
	 
 //	glMatrixMode(GL_PROJECTION); /* switch matrix mode */
	//glLoadIdentity();		//load Identity matrix

	////defines view mode
	//scene.fieldOfViewAngle = 60;
	//gluPerspective(scene.fieldOfViewAngle, 1, 2, 200);
	//glTranslatef(0, 0, -100);

	// /* return to modelview mode */
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	// 
	//glMatrixMode(GL_PROJECTION); /* switch matrix mode */
	//glLoadIdentity();		//load Identity matrix

	////defines view mode
	//scene.fieldOfViewAngle = 60;
	//gluPerspective(scene.fieldOfViewAngle, 1, 2, 200);
	//glTranslatef(0, 0, -100);

	///* return to modelview mode */
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	// 
	//int objectNum = scene.objects.size();

	//for (int o = 0; o < objectNum; o++){

	//	object3D *obj = scene.objects.at(o);
	//	int groupNum = obj->groups->size();

	//	for (int g = 0; g < groupNum; g++){

	//		Group *grp = obj->groups->at(g);
	//		grp->rotation.makeZero();
	//		grp->scale = 1.0f;
	//		grp->translation.makeZero();


	//	}
	//}

	//scene.reset();
}

//void switchState(){
//	if (ScaneState == &CameraState){
//		ScaneState = &GlobalState;
//	}
//	else{
//		ScaneState = &CameraState;
//	}
//}


void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {

	case 'c':
		ScaneState = &CameraState;
		pickState.clearPick();
		printf("camera mode.\n");
		break;
	case 'g':
		ScaneState = &GlobalState;
		pickState.clearPick();
		printf("global mode.\n");
		break;
	case 't':
		pickState.setMode(TRANSLATE);
		printf("trnaslate picking mode.\n");
		ScaneState = &pickState;
		break;
	case 'r':
		pickState.setMode(ROTATE);
		printf("rotate picking mode.\n");
		ScaneState = &pickState;
		break;
	case 's':
		pickState.setMode(SCALE);
		printf("scale picking mode.\n");
		ScaneState = &pickState;
		break;
	case 8: // backSpace
		resetAllMatrices();
		break;

	case 'z':
		printf("camera  location: (%f, %f, %f)\n", scene.camera.Translation.x, scene.camera.Translation.y, scene.camera.Translation.z);
		printf("scene   location: (%f, %f, %f)\n", scene.global.Translation.x, scene.global.Translation.y, scene.global.Translation.z);
		printf("camera Rotattion: (%f, %f, %f)\n", scene.camera.Rotation.x, scene.camera.Rotation.y, scene.camera.Rotation.z);
		printf("scene  Rotattion: (%f, %f, %f)\n\n", scene.global.Rotation.x, scene.global.Rotation.y, scene.global.Rotation.z);
		break;
	default: 
		ScaneState->processNormalKeys(key, x, y);
		break;
	}
}

void processSpecialKeys(int key, int xx, int yy){
	switch (key) {



	case GLUT_KEY_F2:

		if (scene.camera.fieldOfViewAngle < 180){


			scene.camera.fieldOfViewAngle += DELTA_CHANGE_OF_VIEW;
			 
		}

		break;

	case GLUT_KEY_F3:


		if (scene.camera.fieldOfViewAngle > 0){


			scene.camera.fieldOfViewAngle -= DELTA_CHANGE_OF_VIEW;
		 

		}

		break;
	case GLUT_KEY_UP:

		scene.global.scale *= SCALE_FACTOR;
		printf("scale factor: %f\n", scene.global.scale);
		break;
	case GLUT_KEY_DOWN:



		scene.global.scale /= SCALE_FACTOR;
		printf("scale factor: %f\n", scene.global.scale);
		break;
	default:
		ScaneState->processSpecialKeys(key, xx, yy);
		break;

	}
}