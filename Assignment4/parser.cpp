#include "parser.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "Vector3f.h"
#include "object3d.h"
#include "Scene.h"

using namespace std;


 


/*
splits the string by a given delimiter charachter

s- the string to split
delim- the delimiter charachter
elems - the output vector of the splited strings
ignoreEmpty - if true ,dont push empty parsed elements
*/
vector<string> &split(const string &s, char delim, std::vector<string> &elems, bool ignoreEmpty) {

	stringstream ss(s);
	string item;

	while (std::getline(ss, item, delim)) {
		if (ignoreEmpty&&item.empty())
			continue;
		elems.push_back(item);
	}
	return elems;

}


/*
parse a vector given a splited line string
Assuming the first element of the vector is the identifier char ( i.e v , vn .etc)
*/
inline Vector3f parseVec(vector<string> &params){

	return Vector3f(stof(params[1]), stof(params[2]), stof(params[3]));

}



/*
parse a face given a splited line string
Assuming the first element of the vector is the identifier char ( i.e f)
*/

inline Face parsFace(vector<string> &params){


	Face face;
	face.normal = new vector<int>();
	face.vertice = new vector<int>();
	for (int i = 0; i < params.size() - 1; i++){

		int index = params[i + 1].find('/');
		if (index < 0)
			break;



		face.vertice->push_back(stoi(params[i + 1].substr(0, index)));
		face.normal->push_back(stoi(params[i + 1].substr(index + 2)));

	}
	return face;
}



/*
parse an obj file given a string filename
exits on error
*/

void ParseFile(string fileName, Scene &scene){

	std::ifstream file;
	file.open(fileName, ios::in);
	string line;



	if (!file.is_open()){
		printf("error cannot open file %s\n", fileName);
		return;
	}

	object3D* currentObject = NULL;
	Group*	  currentGroup = NULL;

	while (std::getline(file, line))
	{
		if (line.size() == 0 || line[0] == '#')
			continue;

		vector<string> params;
		split(line, ' ', params, true);


		if (params[0] == "o"){
			currentObject = (object3D*)malloc(sizeof (object3D));
			currentObject->name = (params.size() > 1) ? stoi(params[1]) : -1;
			currentObject->groups = new vector<Group*>();
			scene.objects.push_back(currentObject);
			continue;
		}

		if (params[0] == "g"){
			if (currentObject == 0){
				currentObject = (object3D*)malloc(sizeof (object3D));
				currentObject->name = -1;
				currentObject->groups = new vector<Group*>();
				scene.objects.push_back(currentObject);
			}

			currentGroup = new Group();
			currentGroup->name = (params.size() > 1) ? stoi(params[1]) : -1;

			currentObject->groups->push_back(currentGroup);

			currentGroup->faces = new vector<Face>();
			continue;
		}
		if (params[0] == "f"){
			currentGroup->faces->push_back(parsFace(params));
			continue;
		}
		if (params[0] == "v"){
			scene.vertices.push_back(parseVec(params));
			continue;
		}
		if (params[0] == "vn"){
			scene.normals.push_back(parseVec(params));
			continue;

		}

	}

	file.close();

}
