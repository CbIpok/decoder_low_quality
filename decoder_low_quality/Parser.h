#pragma once

#include <string>
#include <vector>
#include "bitstream.h"


class BlockOfMemory // struct with destructure
{
public:
    BlockOfMemory(uint8_t *data,size_t len);

    BlockOfMemory(const BlockOfMemory&) = delete;

    BlockOfMemory(BlockOfMemory&& blockOfMemory) noexcept;

    ~BlockOfMemory();

    uint8_t* data;
    size_t len;    
};



class BlockParser
{
public:

    BlockParser(Bitstream&& bitstream);

    BlockParser(uint8_t *bitstream);

    BlockOfMemory getHeader();
    
    std::vector<BlockOfMemory> getSlises();

    BlockOfMemory getSlice();

    BlockOfMemory gesEos();

    void writeBlockOfMemoryToFile(const BlockOfMemory& blockOfMemory, const std::string& fileName); //make &&f
    
private:
    constexpr static size_t HEADER_SIZE = 96;

    Bitstream bitstream;

    enum class ParseState: uint8_t
    {
        HEADER,
        SLISES,
        EOS,
        DONE
    };

    

   
};


