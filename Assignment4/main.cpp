#include <stdio.h>
 
#include "MatrixHandler.h"
#include "Mouse.h"
#include "Keybaord.h"
#include "parser.h"


 
 
#include "Scene.h"
#include "State.h"
#include "GlobalMode.h"
#include "CameraMode.h"

#include "drawing.h"
#include "PickMode.h"
#include "RotationPickMode.h"
#include "ScalePickMode.h"
#include "TranslationPickMode.h"

using namespace std;


 

Scene scene;
GlobalMode GlobalState(scene);
CameraMode CameraState(scene);
PickMode pickState(scene);
RotationPickMode RotationPickState(scene);
TranslationPickMode TranslationPickState(scene);
ScalePickMode ScalePickState(scene);

State * ScaneState = &CameraState;


/*
	inits the buffers, modelview and projection matrices
*/
void init()
{
 
	glClearColor(0, 0, 0, 1); //black background
	glReadBuffer(GL_BACK);


	glMatrixMode(GL_PROJECTION); /* switch matrix mode */
	glLoadIdentity();		//load Identity matrix
	
	//defines view mode
	scene.fieldOfViewAngle = 60;
	gluPerspective(scene.fieldOfViewAngle, 1, 2, 200);
	glTranslatef(0, 0, -100);
 
	
	glEnable(GL_DEPTH_TEST);  //define in which order the scene will built
	 

	/* return to modelview mode */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void initLight()
{
	//lightning

	//glEnable(GL_COLOR_MATERIAL);
	
	glShadeModel(GL_SMOOTH);
 
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glColorMaterial(GL_BACK, GL_AMBIENT_AND_DIFFUSE);
 
	GLfloat light_ambient[] =	{ 0.5,  0.5,  0.5, 1.0 }; //color
	GLfloat light_diffuse[] =	{ 0.0,  0.5,  0.5, 1.0 }; //color
	GLfloat light_specular[] =	{ 0.0,  0.0,  0.5, 1.0 };
	GLfloat light_position[] =	{ 0.0, -1.0, -1.0, 0.0 };
	 

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
 
	
	

	GLfloat mat_a[] = { 0.3, 0.4, 0.3, 1.0 };
	GLfloat mat_d[] = { 0.7, 0.6, 0.7, 1.0 };
	GLfloat mat_s[] = { 0.5, 0.0, 0.8, 1.0 };
	GLfloat low_sh[] = { 5 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_a);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_d);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_s);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_sh);



}



 
void mydisplay()
{
	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear back buffer	

 
	//glRotatef(0.1, 0, 1,0 ); //rotate scene

	setProjectionMatrix();

	moveScene();
	moveCamera();
	rotateScene();
	rotateCamera();
	moveSelectedObjects();
	rotateSelectedObjects();
	 


	drawAxisLines();
	glPushMatrix();
	setScale();
	glEnable(GL_LIGHTING);
	drawObj(GL_RENDER);
	glDisable(GL_LIGHTING);
	drawCom();
	glPopMatrix();

	
	
	
	
	glutSwapBuffers();
	

}


void disp(int value)
{
	glutPostRedisplay(); //call to mydisplay functoin
	glutTimerFunc(1, disp, 0);

}




int main(int  argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W_WIDTH, W_HEIGHT);
	glutCreateWindow("scene.obj");

	
	 
	init();
	initLight();

	ParseFile("doll.obj", scene);
	glutDisplayFunc(mydisplay);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutTimerFunc(2, disp, 1);
	
	glutMainLoop();
	return 0;
}