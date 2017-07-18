#ifndef CODEDICTIONARY_HPP
#define CODEDICTIONARY_HPP

#include "CodeTree.hpp"

template <typename key, typename value>
class CodeDictionary {
public:
    CodeDictionary(int size = MAX_SYMBOLS);
    ~CodeDictionary();

    void makeDictionary(CodeTree* tree);
    value operator[](const key &k);
    void printDictionary();

private:
    void createKey(Node* node, int depth);

    std::map<key, value> dictionary;
    const int max_symbols;
    char* bits;
};

template <typename key, typename value>
CodeDictionary<key, value>::CodeDictionary(int size): max_symbols(size) {
    bits = new char[max_symbols];
}
template <typename key, typename value>
CodeDictionary<key, value>::~CodeDictionary() {
    delete[] bits;
}

template <typename key, typename value>
void CodeDictionary<key, value>::makeDictionary(CodeTree *tree) {
    createKey(tree->getRoot(), 0);
}

template <typename key, typename value>
value CodeDictionary<key, value>::operator[](const key &str) {
    return dictionary[str];
}

#endif //CODEDICTIONARY_HPP