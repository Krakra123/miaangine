#ifndef _MIA_RENDERER_H
#define _MIA_RENDERER_H

#include "render/vertex/vertex-array.h"
#include "render/vertex/index-buffer.h"
#include "render/shader/shader.h"

namespace mia
{
    class Renderer
    {
    public:
        Renderer() = delete;

    public:
        static void Draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader);
        static void Clear();
    };
}

#endif