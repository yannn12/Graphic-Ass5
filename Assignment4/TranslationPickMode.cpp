#include "TranslationPickMode.h"
#include "PickMode.h"
#include "PickingList.h"

static int pressX=0;
static int pressY=0;
static int pressState = 0;


extern PickMode pickState;
static PickingList *pickinglist = &pickState.pickingList;

TranslationPickMode::TranslationPickMode(Scene& scene) :State(scene)
{
}


TranslationPickMode::~TranslationPickMode(void)
{
}


void TranslationPickMode::mouse(int button, int state, int x, int y){
	pressState = button;
	pressX =x;
	pressY = y;
}

void TranslationPickMode::mouseMotion(int x, int y){

	if(pressState == GLUT_RIGHT_BUTTON){
		vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();
		for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){
			(*grp)->translation.x += ((0.0 + x - pressX) / W_WIDTH) * 50;
			(*grp)->translation.y += ((0.0 + y - pressY) / W_HEIGHT) * 50;
		}
	 
		pressX = x;
		pressY = y;
	}
	else if(pressState == GLUT_MIDDLE_BUTTON){
		vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();
		for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){
			(*grp)->translation.z += ((0.0 + y - pressY) / W_HEIGHT) * 50;
		}
		pressX = x;
		pressY = y;
	}
	else if(pressState ==GLUT_LEFT_BUTTON )
	{
		//this->scene.SceneRotDelta.x += ((0.0+x-pressX)/W_WIDTH);
		//this->scene.SceneRotDelta.y += ((0.0+y-pressY)/W_HEIGHT);
		//pressX = x;
		//pressY = y;
	}
}

void TranslationPickMode::processNormalKeys(unsigned char key, int x, int y){}
void TranslationPickMode::processSpecialKeys(int key, int xx, int yy){}


