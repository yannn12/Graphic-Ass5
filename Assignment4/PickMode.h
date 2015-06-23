#pragma once
#include "state.h"
#include "PickingList.h"
#include <vector>

class PickMode :
	public State


{
public:

	bool press;
	float zValue[4];
	PickingList pickingList;

	PickMode(Scene& scene);

	virtual void mouse(int button, int state, int x, int y);
	virtual void mouseMotion(int x, int y);
	
	virtual ~PickMode(void);

	virtual void processNormalKeys(unsigned char key, int x, int y);
	virtual void processSpecialKeys(int key, int xx, int yy);

private:

	void processHits(GLint hits, GLuint *buffer, float *zValue);
};

