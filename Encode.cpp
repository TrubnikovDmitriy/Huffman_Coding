#include "Encode.hpp"
#include <fstream>


Encode::Encode(string original_name): original_file(original_name),
                                      lists(0), nodes(0) {

// 1) Парсим оригинальный файл вычисляем количество вхождений для каждой буквы
// 2) С помощью кучи сортируем полученный массив и строим из него дерево
// 3) Для удобства создадим словарь<буква, ее новый код>
// 4) Используя словарь, запишем текст из оргинального файла в новой кодировке (функция encode()).


    // (1)
    parser = new Parser();
    vector<Node*> frequency = parser->parseOriginal(original_name);

    // (2)
    MinHeap* heap = new MinHeap(frequency);
    tree = new CodeTree(heap);
//    tree->printTree();
    delete heap;

    // (3)
    codeDictionary = new CodeDictionary(tree);
//    codeDictionary->printDictionary();

// На выходе имеем парсер для файла(1), дерево кодирования(2) и словарь(3) для удобства кодирования
}
Encode::~Encode() {

    delete parser;
    delete tree;
    delete codeDictionary;
}

void Encode::encode(string compressed_name) {

    // Обсчитываем древо, чтобы узнать сколько места отводить
    // под заголовочную информацию в сжатом файле
    countTreeSize(tree->getRoot());

    // Создаем кастомный бинарный райтер
    BinaryWriter* bw = new BinaryWriter(compressed_name + ".dtv");

    // В первые 2+2 байта помещаем заголовочную информацию
    bw->write((char*)&lists, sizeof(u_short));  // Количество листьев
    bw->write((char*)&nodes, sizeof(u_short));  // Количество нод
    // Далее записываем дерево для декодирования
    writeNode(bw, tree->getRoot());

    // Осталось лишь записать сжатый текст
    parser->reopen(original_file);
    u_short ch;
    while(!parser->eof()) {
        ch = parser->getSymbol();
        bw->writeBitSet(codeDictionary->operator[](ch));
    }

    delete bw;
}

void Encode::countTreeSize(Node* node) {

    assert(node != nullptr);

    if (node->left == nullptr || node->right == nullptr) {
        assert(node->left == nullptr && node->right == nullptr);
        ++lists;
        return;
    } else {
        ++nodes;
        countTreeSize(node->left);
        countTreeSize(node->right);
        return;
    }

}
void Encode::writeNode(BinaryWriter *bw, Node *node) {

    if (node->left == nullptr && node->right == nullptr) {
        bw->writeBit(1);
        bw->writeByte(node->ch);
    } else {
        writeNode(bw, node->left);
        writeNode(bw, node->right);
        bw->writeBit(0);
    }
    return;
}
