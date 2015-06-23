#include "PickMode.h"
#include "PickingList.h"
#include "drawing.h"
 
#define PICK_BUFSIZE 512

static int pressX=0;
static int pressY=0;
static int pressState = 0;

void startPicking(GLuint *selectionBuf)
{
	glSelectBuffer(PICK_BUFSIZE, selectionBuf); //declare buffer for input in selection mode
	glRenderMode(GL_SELECT); //change to selecting mode
	glInitNames();			//initialize names stack
	glPushName(0);			//push name
}


void PickMode::processHits(GLint hits, GLuint *buffer, float *zValue)
{
	 
	float z1, z2;
<<<<<<< HEAD
	pick pick;

	if (buffer[0] > 0){
	/*	printf("\nhits: %d\n", hits);
		printf("zValue: ");
		for (int i = 0; i<4; i++){
			printf("z[%d] :%f, ", i, zValue[i]);
		}
		printf("\nbuffer:\n");*/

		float closet = 4294967295.0f;
		for (int i = 0; buffer[i]>0; i += 3 + buffer[i])
		{

			//printf("# :%d,  min: %f,   max: %f,  ", buffer[i], buffer[i + 1] / 4294967295.0, buffer[i + 2] / 4294967295.0);


			/*for (int j = 3; j < 3 + buffer[i]; j++){
				printf("buf[%d]=%d, ", j, buffer[i + j]);
=======
	printf("hits= %d\n",hits);
	printf("\nbuffer\n");
	for (int i = 0; buffer[i]>0; i += 5)
	{
		z1 = buffer[i + 1] / 4294967295.0;
		z2 = buffer[i + 2] / 4294967295.0;

		printf("name = %d\nname2 = %d\n",hits,buffer[i+3],buffer[i+4]);

		printf("z1 = %f ,z2 = %f zValue = %f", z1, z2, zValue[0]);
		printf("name = %f \n",  zValue[4] );
>>>>>>> d029df5ae27704c7a4897a381c3b78c5274061ef

			}
			printf("\n");*/

			if (buffer[i + 1] < closet){

				pick.object = buffer[i + 3];
				pick.group = buffer[i + 4];
				closet = buffer[i + 1];

			}


		}
		 
		if (pickingList.add(pick)){
			printf("added pick:  Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}
		else {
			printf("pick already exist:  Object: = %d ,  Group= %d  \n", pick.object, pick.group);
		}

	}
}

void PickMode::mouse(int button, int state, int x, int y){
	pressState = button;
	pressX =x;
	pressY = y;
	//NEED TO SAPERATE SELECTION MODE AND MOVE MODE

	GLint viewport[4];
	//float pix[4];
	GLuint selectionBuf[PICK_BUFSIZE];

	for (int i = 0; i<PICK_BUFSIZE; i++)
	{
		selectionBuf[i] = 0;
	}
	glGetIntegerv(GL_VIEWPORT, viewport); //reading viewport parameters
	press = !press;

		
	if (press)
	{   //use selection mode to pick

		//glReadPixels(x, viewport[3] - y, 1, 1, GL_RGBA, GL_FLOAT, pix);
		glMatrixMode(GL_PROJECTION);
	 	glReadPixels((GLdouble)x, (GLdouble)viewport[3] - y, 2, 2, GL_DEPTH_COMPONENT, GL_FLOAT, zValue);

		glPushMatrix();	//saves current projection matrix
		glLoadIdentity();

		startPicking(selectionBuf); //preper selection mode

		gluPickMatrix((GLdouble)x, (GLdouble)viewport[3] - y, 1, 1, viewport); //change matrices so only the area of the picking pixel can be seen.
	 
		gluPerspective(scene.fieldOfViewAngle, 1, 2, 200);//return to perspective state 
		glTranslatef(0, 0, -100);

		glMatrixMode(GL_MODELVIEW);
		drawObj(GL_SELECT); //draws board on background


		int hits = glRenderMode(GL_RENDER); //gets hits number 

		glMatrixMode(GL_PROJECTION);
		glPopMatrix(); //restores projection matrix

		glMatrixMode(GL_MODELVIEW);
		processHits(hits, selectionBuf,zValue); //check hits

		//  printf("depth %f hits: %d\n\n",pixels[(viewport[3]-y)*512+x], hits);  
	/*	if (zValue[0]<1.0)
		{
			isPick = true;
			xx = x;
			yy = y;
			if (button == GLUT_RIGHT_BUTTON)
				zMove = true;
			else zMove = false;
		}

	}
	else isPick = false;*/

}

}
void PickMode::mouseMotion(int x, int y){
	return;
	if(pressState == GLUT_RIGHT_BUTTON){
		this->scene.SelectObjLocDelta.x += ((0.0+x-pressX)/W_WIDTH)*50;
		this->scene.SelectObjLocDelta.y -= ((0.0+y-pressY)/W_HEIGHT)*50;
		pressX = x;
		pressY = y;
	}
	else if(pressState == GLUT_MIDDLE_BUTTON){
		this->scene.SelectObjLocDelta.z += ((0.0+y-pressY)/W_HEIGHT)*50;
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
