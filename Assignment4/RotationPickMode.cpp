#include "RotationPickMode.h"


static int pressX=0;
static int pressY=0;
static int pressState = 0;


RotationPickMode::RotationPickMode(Scene& scene) :State(scene)
{
}


RotationPickMode::~RotationPickMode(void)
{
}




void RotationPickMode::mouse(int button, int state, int x, int y){
	pressState = button;
	pressX =x;
	pressY = y;
}

void RotationPickMode::mouseMotion(int x, int y){
	if(pressState == GLUT_RIGHT_BUTTON){
		//this->scene.SelectObjRotDelta.x += ((0.0+x-pressX)/W_WIDTH);
		//this->scene.SelectObjRotDelta.y -= ((0.0+y-pressY)/W_HEIGHT);
		//pressX = x;
		//pressY = y;
	}
	else if(pressState == GLUT_MIDDLE_BUTTON){

	}
	else if(pressState ==GLUT_LEFT_BUTTON )
	{
		this->scene.SelectObjRotDelta.x += ((0.0+x-pressX)/W_WIDTH);
		this->scene.SelectObjRotDelta.y += ((0.0+y-pressY)/W_HEIGHT);
		pressX = x;
		pressY = y;
	}
}

void RotationPickMode::processNormalKeys(unsigned char key, int x, int y){}
void RotationPickMode::processSpecialKeys(int key, int xx, int yy){}