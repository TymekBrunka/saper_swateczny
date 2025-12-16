#pragma once
#include <glad/gl.h>

namespace RR {
    template<typename T>
    class SSBuffer {
    public:
        GLuint id = -1;
        GLsizeiptr length;

        SSBuffer(const T data[], GLsizeiptr n) {
            glGenBuffers(1, &this->id);
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, this->id);
            glBufferData(GL_SHADER_STORAGE_BUFFER, n * sizeof(T), data, GL_DYNAMIC_COPY);
            this->length = n;
        }

        ~SSBuffer() {
            if (this->id != -1) glDeleteBuffers(1, &this->id);
        }

        SSBuffer(SSBuffer&& other) noexcept {
            this->id = other.id;
            this->length = other.length;
            other.id = -1;
        }

        SSBuffer& operator=(SSBuffer&& other) noexcept {
            if (this != &other) {
                this->id = other.id;
                this->length = other.length;
                other.id = -1;
            }
            return *this;
        }

        void bind_index(GLuint index) {
            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, this->id);
        }

        void set(int index, T& value) {
            glBufferSubData(GL_SHADER_STORAGE_BUFFER, (GLintptr)(sizeof(T) * index), (GLintptr)sizeof(T), value);
        }

        void bind() {
            if (this->id != -1) glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
        }
    };
}
