#include "bitstream.h"
#include <cstdint>
#include <cstring>

void readFromBitsream(Bitstream& bitstream, uint8_t *dst, size_t size)
{
    std::memcpy(dst, bitstream.cur, size);
    bitstream.cur += size;
    bitstream.len += size;
}


