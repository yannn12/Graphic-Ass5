#include "TranslationPickMode.h"


TranslationPickMode::TranslationPickMode(Scene& scene) :State(scene)
{
}


TranslationPickMode::~TranslationPickMode(void)
{
}


void TranslationPickMode::mouse(int button, int state, int x, int y){

}

void TranslationPickMode::mouseMotion(int x, int y){}

void TranslationPickMode::processNormalKeys(unsigned char key, int x, int y){}
void TranslationPickMode::processSpecialKeys(int key, int xx, int yy){}


