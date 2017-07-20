#ifndef DECODE_HPP
#define DECODE_HPP

#include <iostream>
#include "Utils.hpp"
#include "CodeTree.hpp"
#include "CodeDictionary.hpp"
#include "BinaryReader.hpp"
#include "Parser.hpp"


class Decode {
public:
    Decode(string compressed_name);
    ~Decode();

    void decode(string decompressed_name);

private:
    CodeTree* tree;
    BinaryReader* br;
    CodeDictionary<string, u_short>* decodeDictionary;
    uint32_t symbols;
    const string compressed_file;
};

#endif //DECODE_HPP


