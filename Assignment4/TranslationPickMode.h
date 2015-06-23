#pragma once
#include "state.h"
class TranslationPickMode :
	public State
{
public:
	TranslationPickMode(Scene& scene);
	virtual ~TranslationPickMode(void);
};

