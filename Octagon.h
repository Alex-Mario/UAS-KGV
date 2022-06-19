#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Object.h"

class Octagon : public Object
{
public:
	static unsigned int vertexArray;
	static unsigned int vertexBuffer;
	static unsigned int indexBuffer;

	Octagon();

	void draw();

	void OctagonVertices(float r, float vertices[9][2]) {
		for (int i = 0; i < 8; i++) {

			vertices[i + 1][0] = r * cos(2 * M_PI * i / 8); //untuk titik x
			vertices[i + 1][1] = r * sin(2 * M_PI * i / 8); //untuk titik y
		}

	}

private:

	float vertices[9][2] = {
	   {0,0}
	};

	unsigned int indexArr[100] = {
		0,1,2, //1
		0,2,3, //2
		0,3,4, //3
		0,4,5,
		0,5,6,
		0,6,7,
		0,7,8,
		0,8,1
	};

};
