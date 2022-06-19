#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Object.h"

class Pentagon : public Object
{
public:
	static unsigned int vertexArray;
	static unsigned int vertexBuffer;
	static unsigned int indexBuffer;

	Pentagon();
	
	void draw();

private:
	float vertices[20] = {
		 1.0f, 1.0f, 1.0f, 0.0f,
		-0.4f, 1.0f, 0.0f, 0.0f,
		-1.0f, 0.1f, 0.0f, 0.0f,
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 1.0f, 1.0f
	};

	unsigned int indexArr[5] = {
	   0,1,2,3,4
	};

	glm::vec4 color = glm::vec4(1.0, 1.0, 1.0, 1.0);

	glm::mat4x4 transformationMat4x4 = glm::mat4x4(1.0f);

};