#include "ScalePickMode.h"

#include "PickMode.h"
#include "PickingList.h"



static int pressX = 0;
static int pressY = 0;
static int pressState = 0;


extern PickMode pickState;
static PickingList *pickinglist = &pickState.pickingList;


ScalePickMode::ScalePickMode(Scene& scene) :State(scene)
{

	
}


ScalePickMode::~ScalePickMode(void)
{
}



void ScalePickMode::mouse(int button, int state, int x, int y){
	pressState = button;
	pressX = x;
	pressY = y;
}

void ScalePickMode::mouseMotion(int x, int y){
	if (pressState == GLUT_LEFT_BUTTON){
		vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();
		for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){
			if (x - pressX != 0)
				(*grp)->scale *= 1+((0.0 + x - pressX) / W_WIDTH) ;
			if (y - pressY != 0)
			(*grp)->scale *= 1+((0.0 + y - pressY) / W_HEIGHT) ;
			//printf("scale of group : %f", (*grp)->scale);
		}
		
		pressX = x;
		pressY = y;
	}
}

void ScalePickMode::processNormalKeys(unsigned char key, int x, int y){}
void ScalePickMode::processSpecialKeys(int key, int xx, int yy){}