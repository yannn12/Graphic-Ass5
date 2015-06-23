#pragma once
#include "state.h"
class RotationPickMode :
	public State
{
public:
	RotationPickMode(Scene& scene);
	virtual ~RotationPickMode(void);
};

