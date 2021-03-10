#include "Parser.h"
#include <cstdint>


int main()
{
    // code not for review
    FILE* fp;

    fp = fopen("1_b_3.jxs", "rb");  // r for read, b for binary

    fseek(fp, 0L, SEEK_END);
    size_t len = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    uint8_t* p = new uint8_t(len);

    fread(p, len, 1, fp);

    Parser parser(p);

    auto block = parser.getHeader();

    parser.writeBlockOfMemoryToFile(block, "header.jxs");


    return 0;
}