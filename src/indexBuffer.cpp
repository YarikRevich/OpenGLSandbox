#include "indexBuffer.hpp"

namespace OpenGL
{
    IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
    {
        glGenBuffers(1, &m_RenderId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    };

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &m_RenderId);
    };

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
    };
    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    };
};