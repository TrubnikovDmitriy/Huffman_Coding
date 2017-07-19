#include <iostream>
#include "BinaryReader.hpp"

using namespace std;

BinaryReader::BinaryReader(const string filename) {

    fin.open(filename, ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cout << filename << "does not exist!" << endl;
        assert(false);
    }
    buffer = 0;
    count = 0;
    temp = 0;
}
BinaryReader::~BinaryReader() {
    fin.close();
}

void BinaryReader::read(char *value, size_t size) {
    // При использовании этой функции, аналогично
    // райтеру, буфер сбрасывается!

    assert(fin.is_open());
    count = 0;

    fin.read(value, size);
}
u_char BinaryReader::readByte() {

    assert(fin.is_open());
    assert(count <= 8);
    temp = 0;

    buffer <<= (8 - count);
    temp |= buffer;

    fin.read((char*)&buffer, 1);
    temp |= (buffer >> count);

    return temp;
}
int BinaryReader::readBit() {

    assert(fin.is_open());
    assert(count <= 8);

    if (count > 0) {
        --count;
        temp = buffer >> count;
        if (temp & 1)
            return 1;
        else
            return 0;
    }

    buffer = 0;
    count = 8;
    fin.read((char*)&buffer, 1);
    return readBit();
}
bool BinaryReader::eof() {
    return fin.eof();
//    return (fin.eof() && count == 0);
}