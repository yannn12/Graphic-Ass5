#pragma once
#include "state.h"
#include "PickingList.h"
#include <vector>

typedef enum Mode{ ROTATE, SCALE, TRANSLATE};

class PickMode :
	public State


{
public:

	Mode mode;
	bool press;
	float zValue[4];
	PickingList pickingList;

	PickMode(Scene& scene);

	void clearPick();

	virtual void mouse(int button, int state, int x, int y);
	virtual void mouseMotion(int x, int y);
	
	virtual ~PickMode(void);

	virtual void processNormalKeys(unsigned char key, int x, int y);
	virtual void processSpecialKeys(int key, int xx, int yy);
	virtual void setMode(Mode mode);

private:

	void processHits(GLint hits, GLuint *buffer, float *zValue);
};

