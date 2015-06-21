#pragma once
#include "state.h"


class PickMode :
	public State


{
public:

	bool press;
	float zValue[4];
	 
	PickMode(Scene& scene);

	virtual void mouse(int button, int state, int x, int y);
	virtual void mouseMotion(int x, int y);
	
	virtual ~PickMode(void);

	virtual void processNormalKeys(unsigned char key, int x, int y);
	virtual void processSpecialKeys(int key, int xx, int yy);
};

