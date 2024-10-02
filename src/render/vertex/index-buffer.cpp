#include "index-buffer.h"

#include <GL/glew.h>

namespace mia
{
    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) :
        _count(count)
    {
        glGenBuffers(1, &_bufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &_bufferId);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}