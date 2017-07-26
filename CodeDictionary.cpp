#include "CodeDictionary.hpp"

using namespace std;

template <>
void CodeDictionary<string, u_short>::createKey(Node* node, int depth) {

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
//        if (code == encode) {
//            auto is_new = enDictionary.insert(pair<u_short, string>(node->ch, str));
//            assert(is_new.second);
//        }

        auto is_new = dictionary.insert(pair<string, u_short>(str, node->ch));
        assert(is_new.second);
        // На всякий случай проверяем, что такой буквы еще не было
    }
}
template <>
void CodeDictionary<u_short, string>::createKey(Node* node, int depth) {

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
        assert(is_new.second);
        // На всякий случай проверяем, что такой буквы еще не было
    }
}


template <>
void CodeDictionary<string, u_short>::printDictionary() {
    if (dictionary.size() != 0) {
        for (auto i = dictionary.begin(); i != dictionary.end(); ++i) {
            std::cout <<  i->first << "(" << (char) i->second << ")" << std::endl;
        }
    } else {
        std::cout << "size 0" << std::endl;
    }
}
template <>
void CodeDictionary<u_short, string>::printDictionary() {
    if (dictionary.size() != 0) {
        for (auto i = dictionary.begin(); i != dictionary.end(); ++i) {
            std::cout << (char) i->first << "(" << i->second << ")" << std::endl;
        }
    } else {
        std::cout << "size 0" << std::endl;
    }
}
