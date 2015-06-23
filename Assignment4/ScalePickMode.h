#pragma once
#include "state.h"
class ScalePickMode :
	public State
{
public:
	ScalePickMode(Scene& scene);
	virtual ~ScalePickMode(void);
};

