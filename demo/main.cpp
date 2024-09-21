#include <iostream>

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
    std::cout << " AAAA " << "\n";
    mia::InitEngine();
    mia::MakeWindow(1280, 720);

    mia::InputManager::Init();

    mia::ShaderUtil shaderUtil;
    shaderUtil.Load("E:/CppProject/mia/src/shaders/vs.shader", "E:/CppProject/mia/src/shaders/fs.shader");

    float points[6] = {
        -.8f, -.5f,
        .0f, .9f,
        .5f, -.7f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), points, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    shaderUtil.Use();

    while (mia::IsRunning()) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(mia::mainWindow);

        mia::InputManager::Update();

        if (mia::InputManager::GetKeyDown(GLFW_KEY_F)) printf("[");
        if (mia::InputManager::GetKey(GLFW_KEY_F)) printf(".");
        if (mia::InputManager::GetKeyUp(GLFW_KEY_F)) printf("]");
    }
}