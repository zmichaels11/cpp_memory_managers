#include "mm/MemoryStack.hpp"

#include <cstdint>

namespace mm {
    void MemoryStack::push() {
        _frames[_frameIndex++] = _ptr;
    }

    void MemoryStack::pop() {
        _ptr = _frames[--_frameIndex];
    }

    void * MemoryStack::malloc(std::size_t size, std::size_t alignment) {
        auto newPtr = _ptr - size;

        newPtr &= ~(alignment - 1);

        _ptr = newPtr;

        return reinterpret_cast<void * > (reinterpret_cast<std::uint8_t *> (_pData + newPtr));
    }

    void MemoryStack::clear() {
        _ptr = _size;
        _frameIndex = 0;
    }
}