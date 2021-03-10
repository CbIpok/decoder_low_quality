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



class Parser
{
public:

    Parser(Bitstream&& bitstream);

    Parser(uint8_t *bitstream);

    BlockOfMemory getHeader();
    
    std::vector<BlockOfMemory> getSlises();

    BlockOfMemory gesEos();

    void writeBlockOfMemoryToFile(const BlockOfMemory& blockOfMemory, const std::string& fileName); //make &&f
    
private:
    constexpr static size_t SIZE_OF_HEADER = 96;

    Bitstream bitstream;

    enum class ParseState: uint8_t
    {
        HEADER,
        SLISES,
        EOS,
        DONE
    };

   

   
};

