#ifndef CODEDICTIONARY_HPP
#define CODEDICTIONARY_HPP

#include "CodeTree.hpp"

class CodeDictionary {
public:
    CodeDictionary(CodeTree* tree, int size = MAX_SYMBOLS);
    ~CodeDictionary();

    void printDictionary();
    std::string operator[](const unsigned short &sh);

private:
    void createKey(Node* node, int depth);

    dic_map dictionary;
    const int max_symbols;
    char* bits;
};

#endif //CODEDICTIONARY_HPP
