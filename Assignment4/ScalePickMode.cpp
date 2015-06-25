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

		Vector3f com = pickinglist->centerOfmass;
		vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();

	 
		for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){
			glPushMatrix();
			glm::mat4 *M = &(*grp)->M;

			glLoadMatrixf( &(*M)[0][0]);
			
			float scale;

			if (x - pressX != 0)
				scale = 1 + ((0.0 + x - pressX) / W_WIDTH);
			if (y - pressY != 0)
				scale = 1 + ((0.0 + y - pressY) / W_HEIGHT);
			
			glTranslatef(com.x, com.y, com.z);
			glScalef(scale, scale, scale);
			glTranslatef(-com.x, -com.y, -com.z);
			
			glGetFloatv(GL_MODELVIEW_MATRIX, &(*M)[0][0]);
			glm::vec4 com((*grp)->centerOfMass.x, (*grp)->centerOfMass.y, (*grp)->centerOfMass.z, 1);
			com = (*M) *com;
			(*grp)->centerOfMass = Vector3f(com.x, com.y, com.z);
			glPopMatrix();
		}
		
		pressX = x;
		pressY = y;
	}
}

void ScalePickMode::processNormalKeys(unsigned char key, int x, int y){}
void ScalePickMode::processSpecialKeys(int key, int xx, int yy){}