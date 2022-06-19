#include "Octagon.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned int Octagon::vertexBuffer = 0;
unsigned int Octagon::indexBuffer = 0;
unsigned int Octagon::vertexArray = 0;

void Octagon::draw()
{
    glBindVertexArray(vertexArray);
    glDrawElements(GL_POLYGON, 100, GL_UNSIGNED_INT, nullptr);
}

Octagon::Octagon()
{
    OctagonVertices(1.0f, vertices);

    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9 * 2, vertices, GL_STATIC_DRAW);

    unsigned int indexBuffer = 0;
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer); // untuk mengikat indexBUffer ke gl_element_array
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 100, indexArr, GL_STATIC_DRAW); // jumlah index yg di deklarasikan

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

}