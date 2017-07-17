#ifndef ENCODE_HPP
#define ENCODE_HPP

#include <iostream>
#include "Utils.hpp"
#include "MinHeap.hpp"
#include "CodeTree.hpp"
#include "CodeDictionary.hpp"
#include "BinaryWriter.hpp"
#include "Parser.hpp"

using namespace std;

class Encode {
public:
    Encode(string original_name);
    ~Encode();

    void encode(string compressed_name);

private:
    void countTreeSize(Node* node);
    void writeNode(BinaryWriter* bw, Node* node);

    Parser* parser;
    CodeTree* tree;
    CodeDictionary* codeDictionary;
    const string original_file;

    unsigned short lists;
    unsigned short nodes;
};

#endif //ENCODE_HPP
