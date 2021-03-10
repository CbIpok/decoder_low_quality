#pragma once
#include <memory>
#include <vector>
#include "bitstream.h"


class BlockOfMemory // struct with destructure
{
public:
    BlockOfMemory(uint8_t *data,size_t len);

    BlockOfMemory(const BlockOfMemory&) = delete;

    BlockOfMemory(BlockOfMemory&& blockOfMemory);

    ~BlockOfMemory();

    uint8_t* data;
    size_t len;
private:
    
};



class Parser
{
public:
    //using BlockOfMemory = std::pair<std::shared_ptr<uint8_t>, size_t>;

    Parser(Bitstream bitstream );

    Parser(uint8_t *bitstream);

    BlockOfMemory getHeader();
    
    std::vector<BlockOfMemory> getSlises();

    BlockOfMemory gesEos();

    void writeBlockOfMemoryToFile(BlockOfMemory& blockOfMemory, std::string fileName); //make &&f
    
private:
    const size_t SIZE_OF_HEADER = 96;

    Bitstream bitstream;

    enum class ParseState: uint8_t
    {
        HEADER,
        SLISES,
        EOS,
        DONE
    };

   

   
};

