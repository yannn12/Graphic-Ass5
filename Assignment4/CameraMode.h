#pragma once
#include "state.h"
class CameraMode :
	public State
{
public:
	virtual void mouse(int button, int state, int x, int y);
	virtual void mouseMotion(int x, int y);
	CameraMode(Scene& scene);
	virtual ~CameraMode(void);

	virtual void processNormalKeys(unsigned char key, int x, int y);
	virtual void processSpecialKeys(int key, int xx, int yy);
};

