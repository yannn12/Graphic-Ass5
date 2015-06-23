#pragma once
#include "state.h"
class TranslationPickMode :
	public State
{
public:
	TranslationPickMode(Scene& scene);
	virtual ~TranslationPickMode(void);

	virtual void mouse(int button, int state, int x, int y) ;
	virtual void mouseMotion(int x, int y) ;
	virtual void processNormalKeys(unsigned char key, int x, int y) ;
	virtual void processSpecialKeys(int key, int xx, int yy);
};

