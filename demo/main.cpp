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

    while (mia::IsRunning()) {
        mia::InputManager::Update();

        if (mia::InputManager::GetKeyDown(GLFW_KEY_F)) printf("[");
        if (mia::InputManager::GetKey(GLFW_KEY_F)) printf(".");
        if (mia::InputManager::GetKeyUp(GLFW_KEY_F)) printf("]");
    }
}