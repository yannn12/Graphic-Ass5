#include "GlobalMode.h"

static int pressX=0;
static int pressY=0;
static int pressState = 0;


static Vector3f zeroVec(0,0,0);


void GlobalMode::mouse(int button, int state, int x, int y){
	if(state ==GLUT_DOWN){
		pressState = button;
		pressX = x;
		pressY = y;
		
	}
	 

}
void GlobalMode::mouseMotion(int x, int y){
	if(pressState == GLUT_RIGHT_BUTTON){
		scene.global.Translation.x += (((float)x - pressX) / W_WIDTH) * 50;
		scene.global.Translation.y -= (((float)y - pressY) / W_HEIGHT) * 50;
		
	}
	else if(pressState == GLUT_MIDDLE_BUTTON){
		scene.global.Translation.z += (((float)y - pressY) / W_HEIGHT) * 50;
		
	}
	else if(pressState ==GLUT_LEFT_BUTTON )
	{
		scene.global.Rotation.x += (((float)x - pressX) / W_WIDTH) *50 ;
		scene.global.Rotation.y += (((float)y - pressY) / W_HEIGHT) *50 ;
		
	}
	pressX = x;
	pressY = y;
}



void GlobalMode::processNormalKeys(unsigned char key, int x, int y){}
void GlobalMode::processSpecialKeys(int key, int xx, int yy){}

GlobalMode::GlobalMode(Scene& scene) :State(scene)
{
}


GlobalMode::~GlobalMode(void)
{
}
