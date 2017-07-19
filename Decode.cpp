#include "Decode.hpp"

Decode::Decode(string compressed_name): compressed_file(compressed_name) {

// 1) Создаем кастомный ридер для бинарного файла, дерево и словарь для удобства
// 2) С помощью ридера считываем заголовочную информацию и формируем дерево
// 3) Из полученного дерева создаем словарь
// 4) Используя словарь, раскодируем файл (функция decode()).


    // (1)
    br = new BinaryReader(compressed_file);
    tree = new CodeTree();
    decodeDictionary = new CodeDictionary<string, u_short>();

    // (2)
    tree->makeTree(br);
//    tree->printTree();

    // (3)
    decodeDictionary->makeDictionary(tree);
    decodeDictionary->printDictionary();

// На выходе имеем: ридер(1) для файла, указатель которого находится в начале
// закодированного текста (заголовочную информацию уже пропарсили),
// дерево кодирования(2) и словарь(3) для удобства декодирования
}
Decode::~Decode() {
    delete decodeDictionary;
    delete tree;
    delete br;
}

void Decode::decode(string decompressed_name) {

    ofstream fout(decompressed_name);
    assert(fout.is_open());

    string encode_symbol = "";
    u_short decode_symbol = 0;

    while(!br->eof()) {
        encode_symbol += to_string(br->readBit());
        decode_symbol = decodeDictionary->operator[](encode_symbol);
        if (decode_symbol != 0) {
            fout << (char)decode_symbol;
            encode_symbol = "";
        }
    }

    fout.close();

    cout << "Файл " << compressed_file << " успешно разархивирован!" << endl;
}