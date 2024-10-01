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

    float points[] = {
         0.5f,  0.5f,
        -0.5f,  0.5f,
        -0.5f, -0.5f,
         0.5f, -0.5f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    mia::VertexBuffer vb(points, 4 * 2 * sizeof(float));
    mia::VertexBufferLayout layout;
    layout.Push<float>(2);

    mia::VertexArray va;
    va.AddBuffer(vb, layout);

    mia::IndexBuffer ib(indices, 3 * 2 * sizeof(unsigned int));

    mia::ShaderUtil::SetAssetPath("E:/CppProject/mia/asset/shader");
    unsigned int shader = mia::ShaderUtil::Load("testing-vs.glsl", "testing-fs.glsl");
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_color");
    glUniform4f(location, 0.2f, 0.5f, 0.1f, 1.0f);

    float r = .2f;
    float inc = .002f;
    while (mia::IsRunning()) {
        glClear(GL_COLOR_BUFFER_BIT);

        va.Bind();
        ib.Bind();

        glUseProgram(shader);

        glUniform4f(location, r, 0.5f, 0.2f, 1.0f);
        if (r > 1.0f || r < 0.0f) inc *= -1;
        r += inc;

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(mia::mainWindow);
        glfwPollEvents();
    }

    glDeleteProgram(shader);
}