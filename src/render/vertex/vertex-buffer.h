#ifndef _MIA_VERTEX_BUFFER_H
#define _MIA_VERTEX_BUFFER_H

#include <vector>
#include <GL/glew.h>

namespace mia
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const void* data, unsigned int count, unsigned int size);
        ~VertexBuffer();

    private:
        unsigned int _bufferId;
        unsigned int _count;

    public:
        void Bind() const;
        void Unbind() const;

        inline unsigned int GetBuffer() const { return _bufferId; }
        inline unsigned int GetCount() const { return _count; }
    };

    // ====================
    struct VertexBufferElement
    {
        unsigned int type;
        unsigned int count;

        static unsigned int GetSizeOfType(unsigned int type) 
        {
            switch (type)
            {
                case GL_FLOAT: return sizeof(GLfloat);
                case GL_UNSIGNED_INT: return sizeof(GLuint);
                default: return 0;
            }
        }
    };

    class VertexBufferLayout
    {
    public:
        VertexBufferLayout();

    private:
        std::vector<VertexBufferElement> _elements;
        unsigned int _stride;

    public:
        template<typename T>
        void Push(unsigned int count);

        inline const std::vector<VertexBufferElement>& GetElements() const { return _elements; }
        inline unsigned int GetStride() const { return _stride; }
    };
}

#endif