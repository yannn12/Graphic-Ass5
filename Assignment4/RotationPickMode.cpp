#include "RotationPickMode.h"
#include "PickMode.h"
#include "PickingList.h"
#include <glm/gtx/transform.hpp>


static int pressX=0;
static int pressY=0;
static int pressState = 0;

extern PickMode pickState;
static PickingList *pickinglist = &pickState.pickingList;

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

	}
	else if(pressState == GLUT_MIDDLE_BUTTON){

	}
	else if(pressState ==GLUT_LEFT_BUTTON )
	{
		Vector3f com = pickinglist->centerOfmass;
		
		vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();

		for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){
			glm::mat4 *M = &(*grp)->M;
				 
			/*(*grp)->rotation.x = (((float)x - pressX) / W_WIDTH)  * 180;
			(*grp)->rotation.y = (((float)y - pressY) / W_HEIGHT) * 180;*/
			
			float rotx = (( (float)x - pressX) / W_WIDTH ) * 180;
			float roty = (( (float)y - pressY) / W_HEIGHT) * 180;

			//rotate:

			glPushMatrix();
			
			glLoadMatrixf( &(*M)[0][0]);
			glTranslatef(com.x, com.y, com.z);

			glRotatef(rotx, 0,1,0);
			glRotatef(roty, 1, 0,0);
	
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

void RotationPickMode::processNormalKeys(unsigned char key, int x, int y){}
void RotationPickMode::processSpecialKeys(int key, int xx, int yy){}