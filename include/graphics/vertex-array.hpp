#ifndef _MIA_VERTEX_ARRAY_H
#define _MIA_VERTEX_ARRAY_H

#include "graphics/vertex-buffer.hpp"

namespace mia
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

    public:
        void AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
    
        void Bind() const;
        void Unbind() const;

    private:
        unsigned int _arrayId;
    };
}

#endif