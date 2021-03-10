#include "Parser.h"

#include <cassert>

#include "bitstream.h"
#include <fstream>
#include <iostream>

Parser::Parser(Bitstream&& bitstream) :
    bitstream(std::move(bitstream))
{

}

Parser::Parser(uint8_t* bitstream)
{
    this->bitstream.buf = bitstream;
    this->bitstream.cur = bitstream;
    this->bitstream.len = 0;
}

BlockOfMemory Parser::getHeader()
{
    uint8_t* buf = new uint8_t[SIZE_OF_HEADER];

    readFromBitsream(bitstream, buf, SIZE_OF_HEADER);
    return { buf, SIZE_OF_HEADER };
}

void Parser::writeBlockOfMemoryToFile(const BlockOfMemory& blockOfMemory, const std::string& fileName)
{

    try {
        std::ofstream out(fileName, std::ios::binary);
        //out.write((char*)blockOfMemory.first, blockOfMemory.second);
        out.write((char*)blockOfMemory.data, blockOfMemory.len);
    }
    catch (const std::exception& e)
    {
        std::cout << "cannot write to file";
    }

    //out.write((char*)(blockOfMemory.first.get()), blockOfMemory.second); //c style cast


    //c code style, code bellow not working

    //FILE* write_ptr;

    //write_ptr = fopen(fileName.c_str(), "wb");  // w for write, b for binary

    //fwrite(blockOfMemory.first, blockOfMemory.second, 1, write_ptr); // write 10 bytes from our buffer

}

BlockOfMemory::BlockOfMemory(uint8_t* data, size_t len) :
    data(data),
    len(len)
{
    assert(data != nullptr);
}


BlockOfMemory::BlockOfMemory(BlockOfMemory&& blockOfMemory) noexcept :
    data(blockOfMemory.data),
    len(blockOfMemory.len)
{
    blockOfMemory.data = nullptr;
}

BlockOfMemory::~BlockOfMemory()
{
    delete[] data;
}
