#include "vertex-array.h"

namespace mia
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &_arrayId);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &_arrayId);
    }

    void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout)
    {
        Bind();
        buffer.Bind();
        const auto& _elements = layout.GetElements();
        unsigned int offset = 0;
        for (int i = 0; i < (int)_elements.size(); i++) {
            const VertexBufferElement& element = _elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, element.type, GL_FALSE, layout.GetStride(), (const void*)offset);
            offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
        }
    }

    void VertexArray::Bind() const 
    {
        glBindVertexArray(_arrayId);
    }

    void VertexArray::Unbind() const 
    {
        glBindVertexArray(0);
    }
}