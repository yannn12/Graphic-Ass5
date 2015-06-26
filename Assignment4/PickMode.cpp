
#include "PickMode.h"
#include "PickingList.h"
#include "drawing.h"
#include "RotationPickMode.h"
#include "ScalePickMode.h"
#include "TranslationPickMode.h"
#include "MatrixHandler.h"


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

	/*printf("z: %f, %f ,%f ,%f .\n", zValue[0], zValue[1], zValue[2], zValue[3]);*/

	float z1, z2;
	pick pick = { -1, -1 };
	printf("\nbuffer\n");
	for (int i = 0; buffer[i]>0; i += 5)
	{
		z1 = buffer[i + 1] /4294967295.0;
		z2 = buffer[i + 2] /4294967295.0;

		int a1 = (zValue[0] <= z1 + 0.0001 && zValue[0] >= z2 - 0.0001) ? 1: 0;
		int a2 = (zValue[0] >= z1 - 0.0001 && zValue[0] <= z2 + 0.0001) ? 1: 0;

		printf("z1 = %f ,z2 = %f z[0] =%f  , a1= %d , a2= %d\n", z1, z2, zValue[0], a1,a2);
		
		//printf(" buffer[%d]: # %d , min %f , max %f, names : %d %d \n", i, buffer[i], buffer[i + 1], buffer[i + 2], buffer[i + 3], buffer[i + 4]);

		if ((zValue[0] <= z1 + 0.0001 && zValue[0] >= z2 - 0.0001) || (zValue[0] >= z1 - 0.0001 && zValue[0] <= z2 + 0.0001))
		{	//try to locate which name is correlated with the pressed pixel according to z value 
			pick.object = buffer[i + 3];
			pick.group  = buffer[i + 4];
		}

	}
	if (pick.object != -1){
		if (pickingList.toggle(pick)){
			printf("added pick:  Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}
		else {
			printf("remove pick: Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}
	}


	/*pick pick;

	if (buffer[0] > 0){
	 
		float closet = 4294967295.0f;
		for (int i = 0; buffer[i]>0; i += 3 + buffer[i])
		{
			 
		    
			printf(" buffer[%d]: # %d , min %d , max %d, names : %d %d \n", i, buffer[i ], buffer[i + 1], buffer[i + 2], buffer[i + 3],buffer[i+4]);
		 
		 
				pick.object = buffer[i + 3];
				pick.group = buffer[i + 4];
				closet = buffer[i + 1];
			
		}

		if (pickingList.toggle(pick)){
			printf("added pick:  Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}
		else {
			printf("remove pick: Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}

		}*/
}

void PickMode::mouse(int button, int state, int x, int y){

	GLint viewport[4];
	float zValue[4];
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

		glMatrixMode(GL_PROJECTION);
		glReadPixels((GLdouble)x, (GLdouble)viewport[3] - y, 2 ,2, GL_DEPTH_COMPONENT, GL_FLOAT, zValue);
	
		

		glPushMatrix();	//saves current projection matrix
		glLoadIdentity(); 

		startPicking(selectionBuf); //preper selection mode

		gluPickMatrix((GLdouble)x, (GLdouble)viewport[3] - y, 1, 1, viewport); //change matrices so only the area of the picking pixel can be seen.
		
		setCamera();
		setGlobal();

		/**************/
		glMatrixMode(GL_MODELVIEW);
		drawObj(GL_SELECT); //draws board on background

	 
		GLint hits = glRenderMode(GL_RENDER); //gets hits number 

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
	pickingList.clearPick();
}

void PickMode::clearPick(){

	pickingList.clearPick();
	
}