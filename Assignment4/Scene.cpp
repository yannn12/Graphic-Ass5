#include "Scene.h"


Scene::Scene(void) :SceneLocation(0, 0, 0), 
					SceneDelta(0, 0, 0), 
					SceneRotate(0, 0, 0), 
					SceneRotDelta(0, 0, 0), 
					scaleFactor(1),	 scaleFactorChanged(false)
					
{
	camera.fieldOfViewAngle = 60;
	camera.Rotation.makeZero();
	camera.Translation = Vector3f(0, 0, -100);

	global.scale = 1;
	global.Rotation.makeZero();
	global.Translation = Vector3f(0, 0, 0);
}


Scene::~Scene(void)
{
}


void Scene::reset( )
{
	/*SceneLocation.makeZero();
	SceneDelta.makeZero();
	CameraLocation.makeZero();
	CameraLocDelta.makeZero();
	SceneRotate.makeZero();
	SceneRotDelta.makeZero();
	CameraRotate.makeZero();
	CameraRotDelta.makeZero();
	fieldOfViewAngle=(0);
	fieldofViewChaned=(false);
	scaleFactor=(1);
	scaleFactorChanged=(false);*/

}