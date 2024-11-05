#ifndef _MIA_ENGINE_H
#define _MIA_ENGINE_H

#include "core/libinclude.h"

namespace mia
{
    void InitWindow(int w, int h);

    void TerminateEngine();

    bool IsRunning();

    extern GLFWwindow* mainWindow;
}

#endif