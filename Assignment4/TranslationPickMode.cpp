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

	
		//vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();
		//for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){

		//	(*grp)->translation.x += (( (float)x - pressX) / W_WIDTH ) * 50;
		//	(*grp)->translation.y += (( (float)y - pressY) / W_HEIGHT) * 50;
		//}
	 
		Vector3f com = pickinglist->centerOfmass;

		vector<Group *> * selectedGroups = pickinglist->getSelectedGroups();

		float translationX = 0;
		float translationY = 0;
		float translationZ = 0;
		/*(*grp)->rotation.x = (((float)x - pressX) / W_WIDTH)  * 180;
		(*grp)->rotation.y = (((float)y - pressY) / W_HEIGHT) * 180;*/
		if (pressState == GLUT_RIGHT_BUTTON || pressState == GLUT_LEFT_BUTTON){
			 translationX = (((float)x - pressX) / W_WIDTH) * 50;
			 translationY = (((float)y - pressY) / W_HEIGHT) * 50;
		}
		else{

			 translationZ = (((float)y - pressY) / W_HEIGHT) * 50;
		}

		for (std::vector<Group *>::iterator grp = selectedGroups->begin(); grp != selectedGroups->end(); ++grp){
			glm::mat4 *M = &(*grp)->M;

			glPushMatrix();

			glLoadMatrixf(&(*M)[0][0]);
			glTranslatef(translationX, translationY, translationZ);
			
			glGetFloatv(GL_MODELVIEW_MATRIX, &(*M)[0][0]);
			glm::vec4 com((*grp)->centerOfMass.x, (*grp)->centerOfMass.y, (*grp)->centerOfMass.z, 1);
			com = (*M) *com;
			(*grp)->centerOfMass = Vector3f(com.x, com.y, com.z);
			glPopMatrix();

		}

		pressX = x;
		pressY = y;
	
 
}

void TranslationPickMode::processNormalKeys(unsigned char key, int x, int y){}
void TranslationPickMode::processSpecialKeys(int key, int xx, int yy){}


