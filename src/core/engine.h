#ifndef _MIA_ENGINE_H
#define _MIA_ENGINE_H

namespace mia
{
    void InitEngine();
    void MakeWindow(int w, int h);

    void TerminateEngine();

    bool IsRunning();
}

#endif