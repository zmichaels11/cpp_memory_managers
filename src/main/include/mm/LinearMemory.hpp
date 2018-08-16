#pragma once

#include <cstddef>

namespace mm {
    class LinearMemory {
        void * _pData;
        std::ptrdiff_t _size;
        std::ptrdiff_t _position;
        std::ptrdiff_t _mark;

    public:
        LinearMemory(std::ptrdiff_t size, void * pData) :
            _pData(pData),
            _size(size),
            _position(0),
            _mark(0) {}

        LinearMemory(const LinearMemory&) = delete;

        LinearMemory(LinearMemory&&) = default;

        LinearMemory& operator= (const LinearMemory&) = delete;

        LinearMemory& operator= (LinearMemory&&) = default;

        void reset();

        void mark();

        void clear();

        void * malloc(std::size_t len, std::size_t alignment = 1);
    };
}