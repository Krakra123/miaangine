#ifndef _MIA_ENGINE_H
#define _MIA_ENGINE_H

#include "core/libinclude.h"

namespace mia
{
    void InitEngine();
    void MakeWindow(int w, int h);

    void TerminateEngine();

    bool IsRunning();

    extern GLFWwindow* mainWindow;
}

#endif