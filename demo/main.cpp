#include <iostream>

#include "mia.h"
#include <glfw3.h>

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
    mia::InitEngine();
    mia::MakeWindow(1280, 720);

    mia::InputManager::Instance().Init();

    ObjA a1(1);
    ObjB b0(0);
    ObjB b1(1);
    {
        ObjA a0(0);
        ObjA a2(153);

        mia::EntityManager::IterateEntities<ObjA>([](ObjA& t){
            t.Notify("in scope");
        });
        mia::EntityManager::IterateEntities<ObjB>([](ObjB& t){
            t.Notify("in scope");
        });
    }

    mia::EntityManager::IterateEntities<ObjB>([](ObjB& t){
        t.Notify("out scope");
    });
    mia::EntityManager::IterateEntities<ObjA>([](ObjA& t){
        t.Notify("out scope");
    });

    while (mia::IsRunning()) {
        mia::InputManager::Instance().Update();
    }

    mia::TerminateEngine();
}