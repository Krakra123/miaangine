#ifndef _MIA_INDEX_BUFFER_H
#define _MIA_INDEX_BUFFER_H

namespace mia
{
    class IndexBuffer
    {
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

    private:
        unsigned int _bufferId;
        unsigned int _count;

    public:
        void Bind() const;
        void Unbind() const;

        inline unsigned int GetBuffer() const { return _bufferId; }
        inline unsigned int GetCount() const { return _count; }
    };
}

#endif