#include "BinaryWriter.hpp"
#include "Utils.hpp"

BinaryWriter::BinaryWriter(string file_name) {

    fout.open(file_name, ios_base::out| ios_base::trunc | ios::binary);
    if (!fout.is_open())
        cout << "Can't open the " << file_name << endl;

    count = 0;
    buffer = 0;
}
BinaryWriter::~BinaryWriter() {

    flushBuffer();
    fout.close();
}

void BinaryWriter::writeBitSet(string byte) {

    assert(count <= 8);

    for (int i = 0; i < byte.size(); ++i) {

        if (count == 8) {
            fout.write((char*)&buffer, sizeof(buffer));
            count = 0;
            buffer = 0;
        }

        assert(byte[i] == '0' || byte[i] == '1');

        buffer <<= 1;
        if (byte[i] == '1')
            buffer |= 1;
        ++count;
    }
}
void BinaryWriter::writeByte(u_short byte) {

    assert(count <= 8);

    for (int i = 0; i < 8; ++i) {

        if (count == 8) {
            fout.write((char*)&buffer, sizeof(buffer));
            count = 0;
            buffer = 0;
        }

        buffer <<= 1;
        if (byte & 128)     //       1000 0000 = 128
            buffer |= 1;    //     * ?xxx xxxx
        byte <<= 1;         // ---------------
                            //       ?000 0000

        ++count;
    }
}
void BinaryWriter::writeBit(u_short bit) {

    assert(count <= 8);

    if (count == 8) {
        fout.write((char*)&buffer, sizeof(buffer));
        count = 0;
        buffer = 0;
    }

    assert(bit == 0 || bit == 1);

    buffer <<= 1;
    buffer |= bit;
    ++count;
}
void BinaryWriter::write(char* value, size_t size) {

    flushBuffer();
    fout.write(value, size);
}

void BinaryWriter::flushBuffer() {

    // Записывает в файл текущее значение буфера и очищает последний.
    // Непроинициализированные биты заполняются нулями.

    assert(count <= 8);
    int shift = 8 - count;
    buffer <<= shift;

    if (count != 0)
        fout.write((char*)&buffer, sizeof(buffer));

    count = 0;
    buffer = 0;
}
void BinaryWriter::toBegin() {
    fout.seekp(0, ios_base::beg);
}
void BinaryWriter::toEnd() {
    fout.seekp(0, ios_base::end);
}
