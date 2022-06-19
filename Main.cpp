#define _USE_MATH_DEFINES                                                                                  
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Util.h"
#include <math.h>
#include <vector>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"
#include "Triangle.h"
#include "Pentagon.h"
#include "Circle.h"
#include "Octagon.h"

float scale = 0.01;
float a = 0.847, b = 0.945, c = 0.952f;


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{   //tombol c untuk random color
    if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {   
        a = (rand() * 1.0f) / RAND_MAX;
        b = (rand() * 1.0f) / RAND_MAX;
        c = (rand() * 1.0f) / RAND_MAX;

        std::cout << a << endl << b << endl << c << endl;
    }

    // scaling / merubah ukuran octagon                                                     
    else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        if (scale < 0.09)
        {
            scale += 0.01;
        }
        else if (scale >= 0.09) {
            scale += 0;
        }
        std::cout << scale << endl;
    }
    else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
        if (scale > 0.01)
        {
            scale -= 0.01;
        }
        else if (scale <= 0.01) {
            scale -= 0;
        }

        std::cout << scale << endl;
    }

}

int main(int key, int scancode, int action, int mods) //main program                                        
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "UAS OOP KGV Kelompok Berners Lee-A", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);

    GLenum err = glewInit();

    Circle c0; // matahari
    c0.setTranslation(glm::vec3(-0.245, 0.655f, 0.0f));
    c0.setScale(glm::vec3(0.6f, 0.9f, 1.0f));
    c0.setColor(glm::vec4(0.98f, 0.89f, 0.098f, 1.0f));

    Triangle t1; //gunung 1
    t1.setTranslation(0.5f, 0.35f, 0.0f);
    t1.setScale(0.5f, 0.5f, 1.0f);
    t1.setColor(glm::vec4(0.0f, 0.7f, 0.1f, 1.0f));

    Triangle t2; //gunung 2
    t2.setTranslation(0.0f, 0.35f, 0.0f);
    t2.setScale(0.5f, 0.5f, 1.0f);
    t2.setColor(glm::vec4(0.4f, 0.9f, 0.2f, 0.5f));

    Triangle t4; //gunung 3
    t4.setTranslation(-0.5f, 0.35f, 0.0f);
    t4.setScale(0.5f, 0.5f, 1.0f);
    t4.setColor(glm::vec4(0.0f, 0.7f, 0.1f, 1.0f));

    Square s1; //aspal
    s1.setTranslation(0.0f, -0.5f, 0.0f);
    s1.setScale(glm::vec3(1.0f, -0.35f, 1.0f));
    s1.setColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));

    Pentagon p1; // pintu depan
    p1.setTranslation(-0.6f, -0.3f, 0.0f);
    p1.setScale(glm::vec3(0.155f, 0.2f, 1.0f));
    p1.setColor(glm::vec4(0.827f, 0.584f, 0.192f, 1.0f));

    Square s2; // kaca truk
    s2.setTranslation(glm::vec3(-0.56f, -0.2f, 0.0f));
    s2.setScale(glm::vec3(0.09f, 0.08f, 1.0f));
    s2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Triangle t3; //kaca truk
    t3.setTranslation(-0.65f, -0.2f, 0.0f);
    t3.setScale(glm::vec3(0.09f, 0.08f, 1.0f));
    t3.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s3; // gagang pintu
    s3.setTranslation(glm::vec3(-0.49f, -0.31f, 0.0f));
    s3.setScale(glm::vec3(0.02f, 0.01f, 1.0f));
    s3.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));

    Square s4; // kotak belakang
    s4.setTranslation(glm::vec3(-0.05f, -0.25f, 0.0f));
    s4.setScale(glm::vec3(0.4f, 0.25f, 1.0f));
    s4.setColor(glm::vec4(0.831f, 0.109f, 0.149f, 1.0f));

    Circle c1; // ban 1
    c1.setTranslation(glm::vec3(-0.6f, -0.53f, 0.0f));
    c1.setScale(glm::vec3(0.5f, 0.8f, 1.0f));
    c1.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Circle c2; // isi ban 1
    c2.setTranslation(glm::vec3(-0.6f, -0.53f, 0.0f));
    c2.setScale(glm::vec3(0.11f, 0.17f, 1.0f));
    c2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Circle c3; // ban 2
    c3.setTranslation(glm::vec3(-0.30f, -0.53f, 0.0f));
    c3.setScale(glm::vec3(0.5f, 0.8f, 1.0f));
    c3.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Circle c4; // isi ban 2
    c4.setTranslation(glm::vec3(-0.30f, -0.53f, 0.0f));
    c4.setScale(glm::vec3(0.11f, 0.17f, 1.0f));
    c4.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Circle c5; // ban 3
    c5.setTranslation(glm::vec3(0.2f, -0.53f, 0.0f));
    c5.setScale(glm::vec3(0.5f, 0.8f, 1.0f));
    c5.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Circle c6; // isi ban 3
    c6.setTranslation(glm::vec3(0.2f, -0.53f, 0.0f));
    c6.setScale(glm::vec3(0.11f, 0.17f, 1.0f));
    c6.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s11; //knalpot
    s11.setTranslation(glm::vec3(0.39f, -0.4f, 0.0f));
    s11.setScale(glm::vec3(0.04f, 0.03f, 1.0f));
    s11.setColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

    Square s12; //asap1
    s12.setRotation(45.0f, glm::vec3(1.0f, 0.0f, 1.0f));
    s12.setTranslation(glm::vec3(0.018f, -0.78f, 0.0f));
    s12.setScale(glm::vec3(0.015f, 0.018f, 1.0f));
    s12.setColor(glm::vec4(0.882f, 0.878f, 0.874f, 1.0f));

    Square s13; //asap2
    s13.setRotation(45.0f, glm::vec3(1.0f, 0.00f, 1.0f));
    s13.setTranslation(glm::vec3(0.074f, -0.84f, 0.0f));
    s13.setScale(glm::vec3(0.023f, 0.023f, 1.0f));
    s13.setColor(glm::vec4(0.882f, 0.878f, 0.874f, 1.0f));

    Square s14; //asap3
    s14.setRotation(45.0f, glm::vec3(1.0f, 0.00f, 1.0f));
    s14.setTranslation(glm::vec3(0.142f, -0.91f, 0.0f));
    s14.setScale(glm::vec3(0.025f, 0.03f, 1.0f));
    s14.setColor(glm::vec4(0.882f, 0.878f, 0.874f, 1.0f));

    Square s15; //marka jalan
    s15.setTranslation(glm::vec3(-0.9f, -0.5f, 0.0f));
    s15.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s15.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s16; //marka jalan 2
    s16.setTranslation(glm::vec3(-0.65f, -0.5f, 0.0f));
    s16.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s16.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s17; //marka jalan 3
    s17.setTranslation(glm::vec3(-0.4f, -0.5f, 0.0f));
    s17.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s17.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s18; //marka jalan 4
    s18.setTranslation(glm::vec3(-0.15f, -0.5f, 0.0f));
    s18.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s18.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s19; //marka jalan 5
    s19.setTranslation(glm::vec3(0.1f, -0.5f, 0.0f));
    s19.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s19.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s20; //marka jalan 6
    s20.setTranslation(glm::vec3(0.35f, -0.5f, 0.0f));
    s20.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s20.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s21; //marka jalan 7
    s21.setTranslation(glm::vec3(0.6f, -0.5f, 0.0f));
    s21.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s21.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    Square s22; //marka jalan 8
    s22.setTranslation(glm::vec3(0.85f, -0.5f, 0.0f));
    s22.setScale(glm::vec3(0.08f, 0.045f, 1.0f));
    s22.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    vector<Object*> Objects;
    Objects.push_back(&t1);
    Objects.push_back(&t2);
    Objects.push_back(&t4);
    Objects.push_back(&c0);

    Objects.push_back(&s1);
    Objects.push_back(&s15);
    Objects.push_back(&s16);
    Objects.push_back(&s17);
    Objects.push_back(&s18);
    Objects.push_back(&s19);
    Objects.push_back(&s20);
    Objects.push_back(&s21);
    Objects.push_back(&s22);

    Objects.push_back(&p1);
    Objects.push_back(&s2);
    Objects.push_back(&t3);
    Objects.push_back(&s3);
    Objects.push_back(&s4);

    Objects.push_back(&c1);
    Objects.push_back(&c2);
    Objects.push_back(&c3);
    Objects.push_back(&c4);
    Objects.push_back(&c5);
    Objects.push_back(&c6);

    Objects.push_back(&s11);
    Objects.push_back(&s12);
    Objects.push_back(&s13);
    Objects.push_back(&s14);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    Object* Object;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        Octagon o1; // logo
        o1.setTranslation(glm::vec3(-0.05f, -0.25f, 0.0f));
        o1.setScale(glm::vec3(0.12f + scale, 0.12f + scale, 1.0f));
        o1.setColor(glm::vec4(a, b, c, 1.0f));

        Objects.push_back(&o1);

        a = (rand() * 1.0f) / RAND_MAX;
        b = (rand() * 1.0f) / RAND_MAX;
        c = (rand() * 1.0f) / RAND_MAX;

        glfwWaitEventsTimeout(1);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.9f, 1.0, 0.8f, 1.0f); // warna window

        glUseProgram(program);

        //glDrawArrays(GL_TRIANGLES,0,6);
        for (int i = 0; i < Objects.size(); i++)
        {
            Object = Objects.at(i);
            glUniform4fv(uColor, 1, &(Object->getColor()[0]));
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &(Object->getTransformationMat4x4()[0][0]));
            Objects.at(i)->draw();
        }


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}