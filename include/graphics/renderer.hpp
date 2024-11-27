#ifndef _MIA_RENDERER_H
#define _MIA_RENDERER_H

#include "graphics/vertex-array.hpp"
#include "graphics/index-buffer.hpp"
#include "graphics/shader.hpp"

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