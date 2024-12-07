#include <iostream>
#include <fstream>

#include "../include/mia.hpp"

class A : public mia::entity 
{
public:
    int x;
    A(int x): mia::entity(std::type_index(typeid(A))), x(x) {}

    virtual void print() 
    {
        MIA_LOG_INFO("A: {}", x);
    }
};

class B : public mia::entity 
{
public:
    int x;
    B(int x): mia::entity(std::type_index(typeid(B))), x(x) {}

    virtual void print() 
    {
        MIA_LOG_INFO("B: {}", x);
    }
};

int main(int argv, char** args)
{
    mia::InitWindow(1280, 720);
    mia::InputManager::Init();

    mia::init_core();

    A aa(1);
    A ab(2);
    A ac(3);
    B ba(1);
    B bb(2);
    B bc(3);
    mia::iterate_entities<A>([](A& t) { t.print(); });
    mia::iterate_entities<B>([](B& t) { t.print(); });

    glm::vec2 a(10.0 / 3, 12);
    glm::vec2 b(10.0 / 3, (6.0 - 4) * 6);
    printf("%.9f %.9f : %.9f %.9f -> %d", a.x, a.y, b.x, b.y, a == b);
    // mia::Vector2 a = {3.333333, 12};
    // mia::Vector2 b = {10.0 / 3, (6.0 - 4) * 6};
    // printf("%.9f %.9f : %.9f %.9f -> %d", a.x, a.y, b.x, b.y, a == b);

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

    mia::VertexBuffer vb(points, 4 * 2, sizeof(float));
    mia::VertexBufferLayout layout;
    layout.Push<float>(2);

    mia::VertexArray va;
    va.AddBuffer(vb, layout);

    mia::IndexBuffer ib(indices, 3 * 2);

    mia::ShaderUtil::SetAssetPath("E:/CppProject/mia/asset/shader");
    mia::Shader shader("testing-vs.glsl", "testing-fs.glsl");

    float r = .2f;
    float inc = .002f;
    while (mia::IsRunning()) {
        mia::Renderer::Clear();

        shader.SetUniform4f("u_color", r, 0.5f, 0.2f, 1.0f);
        if (r > 1.0f || r < 0.0f) inc *= -1;
        r += inc;

        mia::Renderer::Draw(va, ib, shader);

        glfwSwapBuffers(mia::mainWindow);
        glfwPollEvents();
    }

    return 0;
}