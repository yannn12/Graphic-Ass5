
#include "State.h"
#include "Mouse.h"
//#include "glut.h"


//void mouseCamera(int button, int state, int x, int y) {
//
//}
GLfloat rot=0;
extern State * ScaneState;

void mouseGlobal(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		rot = 0;
		break;
	case GLUT_RIGHT_BUTTON:
		if (rot == 0)
		if (x>y)
			rot = 0.01;
		else rot = -0.01;
		else (rot += rot);
		break;
	case GLUT_MIDDLE_BUTTON:
		break;
	}
}

void mouseMotion(int x, int y){

	ScaneState->mouseMotion(x, y);

}


void mouse(int button, int state, int x, int y)
{
	ScaneState->mouse(button, state, x, y);

}
 