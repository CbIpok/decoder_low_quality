#pragma once
#include <memory>
#include <vector>
#include "bitstream.h"




class Parser
{
public:
    using BlockOfMemory = std::pair<uint8_t*, size_t>; //memory leak, make shared
    //using BlockOfMemory = std::pair<std::shared_ptr<uint8_t>, size_t>;

    Parser(Bitstream bitstream );

    Parser(uint8_t *bitstream);

    BlockOfMemory getHeader();
    
    std::vector<BlockOfMemory> getSlises();

    BlockOfMemory gesEos();

    void writeBlockOfMemoryToFile(BlockOfMemory blockOfMemory, std::string fileName); //make &&f
    
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

