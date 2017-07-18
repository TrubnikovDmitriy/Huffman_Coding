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
//    void countTreeSize(Node* node);
//    void writeNode(BinaryWriter* bw, Node* node);

    CodeTree* tree;
    BinaryReader* br;
    const string compressed_file;
    CodeDictionary<string, u_short>* decodeDictionary;
};

#endif //DECODE_HPP


