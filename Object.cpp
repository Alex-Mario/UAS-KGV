#include "Object.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Object::setColor(glm::vec4 newColor)
{
    color = glm::vec4(newColor);
}

glm::vec4 Object::getColor()
{
    return color;
}

void Object::setTranslation(glm::vec3 newTranslation)
{
    transformationMat4x4 = glm::translate(transformationMat4x4, newTranslation);
}

void Object::setTranslation(float transX, float transY, float transZ)
{
    setTranslation(glm::vec3(transX, transY, transZ));
}

glm::mat4x4 Object::getTransformationMat4x4()
{
    return transformationMat4x4;
}

void Object::setRotation(float angle, glm::vec3 axis)
{
    transformationMat4x4 = glm::rotate(transformationMat4x4, angle, axis);
}

void Object::setScale(glm::vec3 newScale)
{
    transformationMat4x4 = glm::scale(transformationMat4x4, newScale);
}

void Object::setScale(float scaleX, float scaleY, float scaleZ)
{
    setScale(glm::vec3(scaleX, scaleY, scaleZ));
}

void Object::draw()
{

}
