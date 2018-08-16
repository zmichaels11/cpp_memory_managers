#pragma once

#include <cstddef>

namespace mm {
    constexpr std::size_t MAX_FRAMES = 8;

    class MemoryStack {
        void * _pData;
        std::ptrdiff_t _size;
        std::ptrdiff_t _frames[MAX_FRAMES];
        std::ptrdiff_t _ptr;
        std::size_t _frameIndex;

    public:
        MemoryStack(std::ptrdiff_t size, void * pData) :
            _pData(pData),
            _size(size),
            _ptr(size),
            _frameIndex(0) {}

        void push();

        void pop();

        void * malloc(std::size_t size, std::size_t alignment = 1);

        void clear();
    };
}