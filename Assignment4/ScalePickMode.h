#pragma once
#include "state.h"
class ScalePickMode :
	public State
{
public:
	ScalePickMode(Scene& scene);
	virtual ~ScalePickMode(void);

	virtual void mouse(int button, int state, int x, int y) ;
	virtual void mouseMotion(int x, int y) ;
	virtual void processNormalKeys(unsigned char key, int x, int y) ;
	virtual void processSpecialKeys(int key, int xx, int yy);
};

