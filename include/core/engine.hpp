#ifndef _MIA_ENGINE_H
#define _MIA_ENGINE_H

#include "core/libinclude.hpp"

namespace mia
{
    void init_core();

    void InitWindow(int w, int h);

    void TerminateEngine();

    bool IsRunning();

    extern GLFWwindow* mainWindow;
}

#endif