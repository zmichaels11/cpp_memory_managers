#include "mm/LinearMemory.hpp"

#include <cstdint>

namespace mm {
    namespace {
        template<typename T>
        T alignUp(T a, T b) {
            return (a + b - static_cast<T> (1)) / b * b;
        }
    }

    void LinearMemory::reset() {
        _position = _mark;
    }

    void LinearMemory::mark() {
        _position = _mark;
    }

    void LinearMemory::clear() {
        _position = 0;
        _mark = 0;
    }

    void * LinearMemory::malloc(std::size_t len, std::size_t alignment) {
        auto offset = alignUp(_position, static_cast<std::ptrdiff_t> (alignment));

        if (offset >= _size) {
            offset = 0;
        }

        _position = offset + len;

        return reinterpret_cast<void * > (reinterpret_cast<std::uint8_t * > (_pData + offset));
    }
}