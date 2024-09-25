#include <iostream>
#include <fstream>

#include "mia.h"

class ObjA : public mia::Entity
{
public:
    ObjA(int s) : mia::Entity(typeid(ObjA)) 
    {
        id = s;
    }

    int id;

    void Notify(const char* message)
    {
        printf("A-%d: %s\n", id, message);
    }
};
class ObjB : public mia::Entity
{
public:
    ObjB(int s) : mia::Entity(typeid(ObjB)) 
    {
        id = s;
    }

    int id;

    void Notify(const char* message)
    {
        printf("B-%d: %s\n", id, message);
    }
};

int main()
{
    mia::InitWindow(1280, 720);
    mia::InputManager::Init();

    float points[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(points), &points, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    mia::ShaderUtil::SetAssetPath("E:/CppProject/mia/asset/shader");
    unsigned int program = mia::ShaderUtil::Load("testing-vs.glsl", "testing-fs.glsl");
    glUseProgram(program);

    while (mia::IsRunning()) {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(mia::mainWindow);
        glfwPollEvents();
    }

    glDeleteProgram(program);
}