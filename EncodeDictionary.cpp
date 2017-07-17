#include "CodeDictionary.hpp"

using namespace std;

CodeDictionary::CodeDictionary(CodeTree* tree, int size): max_symbols(size) {

    bits = new char[max_symbols];
    createKey(tree->getRoot(), 0);
}
CodeDictionary::~CodeDictionary() {
    delete[] bits;
}

void CodeDictionary::createKey(Node* node, int depth) {

    assert(depth < max_symbols);

    // Формируем новую кодировку в зависимости
    // от расположения листа в древе
    if (node->left != nullptr) {
        bits[depth] = '0';
        createKey(node->left, depth + 1);
    }
    if (node->right != nullptr) {
        bits[depth] = '1';
        createKey(node->right, depth + 1);
    }


    if (node->left == nullptr && node->right == nullptr) {
        // Если текущая нода - лист, то вставляем
        // в словарь новую кодировку для данной буквы

        string str = "";
        for (int i = 0; i < depth; ++i)
            str += bits[i];

        auto is_new = dictionary.insert(pair<u_short, string>(node->ch, str));
        // На всякий случай проверяем, что такой буквы еще не было
        assert(is_new.second);
    }

}

void CodeDictionary::printDictionary() {
    for (auto i = dictionary.begin(); i != dictionary.end(); ++i) {
        cout << (char)i->first << "(" << i->second << ")" << endl;
    }
}
std::string CodeDictionary::operator[](const unsigned short &sh) {
    return dictionary[sh];
}