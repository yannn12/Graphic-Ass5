#include "PickMode.h"
#include "drawing.h"
 
#define PICK_BUFSIZE 512


void startPicking(GLuint *selectionBuf)
{
	glSelectBuffer(PICK_BUFSIZE, selectionBuf); //declare buffer for input in selection mode
	glRenderMode(GL_SELECT); //change to selecting mode
	glInitNames();			//initialize names stack
	glPushName(-1);			//push name
}

void processHits(GLint hits, GLuint *buffer, float *zValue)
{
	 
	float z1, z2;
	printf("\nbuffer\n");
	for (int i = 0; buffer[i]>0; i += 5)
	{
		z1 = buffer[i + 1] / 4294967295.0;
		z2 = buffer[i + 2] / 4294967295.0;

		printf("z1 = %f ,z2 = %f zValue = %f", z1, z2, zValue[0]);
		printf("name = %f \n",  zValue[4] );


		//if ((zValue[0] <= z1 + 0.0001 && zValue[0] >= z2 - 0.0001) || (zValue[0] >= z1 - 0.0001 && zValue[0] <= z2 + 0.0001))
		//{	//try to locate which name is correlated with the pressed pixel according to z value 
		//	ii = buffer[i + 3];
		//	jj = buffer[i + 4];
		//}

	}
}

void PickMode::mouse(int button, int state, int x, int y){
	 
	GLint viewport[4];
	float pix[4];
	GLuint selectionBuf[PICK_BUFSIZE];

	for (int i = 0; i<PICK_BUFSIZE; i++)
	{
		selectionBuf[i] = 0;
	}
	glGetIntegerv(GL_VIEWPORT, viewport); //reading viewport parameters
	press = !press;


	if (press)
	{   //use selection mode to pick

		glReadPixels(x, viewport[3] - y, 1, 1, GL_RGBA, GL_FLOAT, pix);
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
