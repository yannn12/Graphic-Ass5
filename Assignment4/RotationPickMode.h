#pragma once
#include "state.h"
class RotationPickMode :
	public State
{
public:
	RotationPickMode(Scene& scene);
	virtual ~RotationPickMode(void);


	virtual void mouse(int button, int state, int x, int y);
	virtual void mouseMotion(int x, int y);
	virtual void processNormalKeys(unsigned char key, int x, int y) ;
	virtual void processSpecialKeys(int key, int xx, int yy);
};

