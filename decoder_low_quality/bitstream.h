#pragma once
#include <cstdint>
#include <string>

struct Bitstream
{
    size_t len;
    uint8_t *cur;
    uint8_t *buf;
};


void readFromBitsream(Bitstream bitstream, uint8_t* src, size_t size);

