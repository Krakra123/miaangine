#include "vertex-buffer.h"

#include <GL/glew.h>

namespace mia
{
    VertexBuffer::VertexBuffer(const void* data, unsigned int size) 
    {
        glGenBuffers(1, &_bufferId);
        glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &_bufferId);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    // ====================
    template<>
    void VertexBufferLayout::Push<unsigned int>(unsigned int count) 
    {
        _elements.push_back({GL_UNSIGNED_INT, count});
        _stride += sizeof(GLuint) * count;
    }

    template<>
    void VertexBufferLayout::Push<float>(unsigned int count) 
    {
        _elements.push_back({GL_FLOAT, count});
        _stride += sizeof(GLfloat) * count;
    }
}