#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Object.h"

class Circle : public Object
{
public:
	static unsigned int vertexArray;
	static unsigned int vertexBuffer;
	static unsigned int indexBuffer;

	Circle();
	
	void draw();

	void CircleVertices(float r, float vertices[20][2]) {
		for (int i = 0; i < 19; i++) {

			vertices[i + 1][0] = r * cos(2 * M_PI * i / 18); //untuk titik x
			vertices[i + 1][1] = r * sin(2 * M_PI * i / 18); //untuk titik y
		}

	}

private:

	float vertices[20][2] = {
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
		0,8,9,
		0,9,10,
		0,10,11,
		0,11,12,
		0,12,13,
		0,13,14,
		0,14,15,
		0,15,16,
		0,16,17,
		0,17,18,
		0,18,19,
		0,19,1 //19
	};

};

