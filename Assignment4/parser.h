#pragma once

#include "Vector3f.h"
#include "object3d.h"
#include "Scene.h"

void ParseFile(string fileName, Scene &scene);
Vector3f parseVec(vector<string> &params);
Face parsFace(vector<string> &params);


