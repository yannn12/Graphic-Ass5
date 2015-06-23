#include "ScalePickMode.h"


ScalePickMode::ScalePickMode(Scene& scene) :State(scene)
{
}


ScalePickMode::~ScalePickMode(void)
{
}



void ScalePickMode::mouse(int button, int state, int x, int y){

}

void ScalePickMode::mouseMotion(int x, int y){}

void ScalePickMode::processNormalKeys(unsigned char key, int x, int y){}
void ScalePickMode::processSpecialKeys(int key, int xx, int yy){}