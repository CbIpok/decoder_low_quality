#include "Parser.h"

#include <cassert>

#include "bitstream.h"
#include <fstream>
#include <iostream>
#include "bitstream.h"

BlockParser::BlockParser(Bitstream&& bitstream) :
    bitstream(std::move(bitstream))
{

}

BlockParser::BlockParser(uint8_t* bitstream, size_t size)
{
    this->bitstream.buf = bitstream;
    this->bitstream.cur = bitstream;
    this->bitstream.len_readed = 0;
    this->bitstream.size = size;

}


BlockOfMemory BlockParser::getHeader()
{
    uint8_t* buf = new uint8_t[HEADER_SIZE];

    readFromBitsream(bitstream, buf, HEADER_SIZE);
    return { buf, HEADER_SIZE };
}



void writeBlockOfMemoryToFile(const BlockOfMemory& blockOfMemory, const std::string& fileName)
{

    try 
    {
        std::ofstream out(fileName, std::ios::binary);
        //out.write((char*)blockOfMemory.first, blockOfMemory.second);
        out.write((char*)blockOfMemory.data, blockOfMemory.len);
    }
    catch (const std::exception& e)
    {
        std::cout << "cannot write to file";
    }
}


BlockOfMemory::BlockOfMemory(uint8_t* data, size_t size) :
    data(data),
    len(size)
{
    assert(data != nullptr);
    bitstream.buf = data;
    bitstream.cur = data;
    bitstream.len_readed = 0;
    bitstream.size = size;
}


BlockOfMemory::BlockOfMemory(BlockOfMemory&& blockOfMemory) noexcept :
    data(blockOfMemory.data),
    len(blockOfMemory.len)
{
    blockOfMemory.data = nullptr;
}

BlockOfMemory::~BlockOfMemory()
{
    delete[] data; //todo make smart pointer
}

PictureHeader Parser::parseHeader(BlockOfMemory& blockOfMemory)
{
    PictureHeader pictureHeader;
	int lpih = 26;
	int precinct_height;
	uint32_t val;
	readFromBitsream(blockOfMemory.bitstream, (uint8_t*)(&val), XS_MARKER_NBYTES);
	assert(val == XS_MARKER_PIH);
	//nbits += bitunpacker_read(bitstream, &val, XS_MARKER_NBITS);
	//assert(val == lpih);
	//nbits += bitunpacker_read(bitstream, &val, 32);
	//conf->bitstream_nbytes = val;

	//nbits += bitunpacker_read(bitstream, &val, 16);

	//nbits += bitunpacker_read(bitstream, &val, 16);

	//nbits += bitunpacker_read(bitstream, &val, 16);
	//im->w[0] = val;

	//nbits += bitunpacker_read(bitstream, &val, 16);
	//im->h[0] = val;


	//nbits += bitunpacker_read(bitstream, &val, 16);
	//conf->col_sz = val;

	//nbits += bitunpacker_read(bitstream, &val, 16);
	//conf->slice_height = val;
	//nbits += bitunpacker_read(bitstream, &val, 8);
	//im->ncomps = val;
	//nbits += bitunpacker_read(bitstream, &val, 8);
	//conf->group_size = val;
	//nbits += bitunpacker_read(bitstream, &val, 8);
	//conf->sigflags_group_width = val;
	//nbits += bitunpacker_read(bitstream, &val, 8);
	//conf->in_depth = val;
	//nbits += bitunpacker_read(bitstream, &val, 4);
	//conf->quant = val;
	//nbits += bitunpacker_read(bitstream, &val, 4);
	//assert(val == 4);
	//nbits += bitunpacker_read(bitstream, &val, 1);
	//assert(val == 0);
	//nbits += bitunpacker_read(bitstream, &val, 3);
	//assert(val == 0);
	//nbits += bitunpacker_read(bitstream, &val, 4);
	//conf->rct = val;
	//nbits += bitunpacker_read(bitstream, &val, 4);
	//conf->ndecomp_h = val;
	//nbits += bitunpacker_read(bitstream, &val, 4);
	//conf->ndecomp_v = val;
	//precinct_height = (1 << conf->ndecomp_v);
	//conf->slice_height *= precinct_height;
	//nbits += bitunpacker_read(bitstream, &val, 4);
	//conf->dq_type = val;
	//nbits += bitunpacker_read(bitstream, &val, 2);
	//conf->sign_opt = val;
	//nbits += bitunpacker_read(bitstream, &val, 2);
	//conf->gc_run_sigflags_zrcsf = val;
	//conf->gc_run_sigflags_zrf = (!val);



    return PictureHeader();
}
