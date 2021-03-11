#pragma once

#include <string>
#include <vector>
#include <memory>
#include "bitstream.h"
#include "type.h"
#include <climits>



class BlockOfMemory // struct with destructure
{
public:
    BlockOfMemory(uint8_t *data,size_t size);

    BlockOfMemory(const BlockOfMemory&) = delete;

    BlockOfMemory(BlockOfMemory&& blockOfMemory) noexcept;

    ~BlockOfMemory();

    uint8_t* data;
    size_t len;
    Bitstream bitstream;
};



class BlockParser
{
public:

    BlockParser(Bitstream&& bitstream);

    BlockParser(uint8_t *bitstream, size_t size);

    BlockOfMemory getHeader(); //todo SLICE HEADER LEN IS NOT CONSTANT!!
    
    std::vector<BlockOfMemory> getSlises();

    BlockOfMemory getSlice();

    BlockOfMemory gesEos();

    
    
private:
    constexpr static size_t HEADER_SIZE = 96;

    Bitstream bitstream;

    std::unique_ptr<uint8_t> buf;

    enum class ParseState: uint8_t
    {
        HEADER,
        SLISES,
        EOS,
        DONE
    };

    

   
};


class Parser
{
public:
    Parser() = default;

    ~Parser() = default;

    PictureHeader parseHeader(BlockOfMemory& blockOfMemory);

    


private:

    template <typename T>
    T swap_endian(T u)
    {
        static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");

        union
        {
            T u;
            unsigned char u8[sizeof(T)];
        } source, dest;

        source.u = u;

        for (size_t k = 0; k < sizeof(T); k++)
            dest.u8[k] = source.u8[sizeof(T) - k - 1];

        return dest.u;
    }
};




//methods


void writeBlockOfMemoryToFile(const BlockOfMemory& blockOfMemory, const std::string& fileName);