#ifndef WRITER_HPP
#define WRITER_HPP

#include <iostream>
#include <fstream>

using namespace std;

class BinaryWriter {
public:
    BinaryWriter(const string file_name);
    ~BinaryWriter();

    void writeBitSet(string byte);
    void writeByte(u_short byte);
    void writeBit(u_short bit);
    void write(char* value, size_t size);
    void flushBuffer();

    void toBegin();
    void toEnd();

private:
    unsigned char buffer;
    ofstream fout;
    int count;
};

#endif //WRITER_HPP
