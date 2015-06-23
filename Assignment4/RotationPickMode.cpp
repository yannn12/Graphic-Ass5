#include "RotationPickMode.h"


RotationPickMode::RotationPickMode(Scene& scene) :State(scene)
{
}


RotationPickMode::~RotationPickMode(void)
{
}




void RotationPickMode::mouse(int button, int state, int x, int y){

}

void RotationPickMode::mouseMotion(int x, int y){}

void RotationPickMode::processNormalKeys(unsigned char key, int x, int y){}
void RotationPickMode::processSpecialKeys(int key, int xx, int yy){}