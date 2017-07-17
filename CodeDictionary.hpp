#ifndef CODEDICTIONARY_HPP
#define CODEDICTIONARY_HPP

#include "CodeTree.hpp"

class EncodeDictionary {
public:
    EncodeDictionary(CodeTree* tree, int size = MAX_SYMBOLS);
    ~EncodeDictionary();

    void printDictionary();
    std::string operator[](const u_short &sh);
    u_short operator[](const std::string &str);

private:
    void createKey(Node* node, int depth);

    dic_map dictionary;
    const int max_symbols;
    char* bits;
};

#endif //CODEDICTIONARY_HPP
