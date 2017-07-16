#ifndef WRITER_HPP
#define WRITER_HPP

#include <iostream>
#include <fstream>

using namespace std;

class BinaryWriter {
public:
    BinaryWriter(string file_name);
    ~BinaryWriter();

    void writeByte(string byte);
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