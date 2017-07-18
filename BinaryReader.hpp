#ifndef BINARYREADER_HPP
#define BINARYREADER_HPP

#include <fstream>
#include "Utils.hpp"

class BinaryReader {
public:
    BinaryReader(const std::string filename);
    ~BinaryReader();

    void read(char* value, size_t size);
    u_char readByte();
    int readBit();
    bool eof();

private:
    std::ifstream fin;
    u_char buffer;
    u_char temp;
    int count;
};

#endif //BINARYREADER_HPP
