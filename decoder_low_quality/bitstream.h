#pragma once

#include <cstdint>

struct Bitstream
{
    size_t size;
    size_t len_readed;
    uint8_t *cur;
    uint8_t *buf; 
};


void readFromBitsream(Bitstream& bitstream, uint8_t* dst, size_t size);

