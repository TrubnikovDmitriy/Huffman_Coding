#include <fstream>
#include <iostream>
#include <ctime>
#include <map>

#include "MinHeap.hpp"
#include "CodeTree.hpp"
#include "CodeDictionary.hpp"
#include "BinaryWriter.hpp"

using namespace std;


vector<Node*> parser(string name) {

    vector<Node *> frequency;

    ifstream fin(name, ios::in);
    if (!fin.is_open()) {
        cout << "File " << name << " doesn't exist!" << endl;
        return frequency;
    }

    map<u_short, uint64_t> freq_char;
    u_short ch = (u_short) fin.get();
    pair<map<u_short, uint64_t>::iterator, bool> is_new;

    while (!fin.eof()) {

        // Считываем по одному символу и пытаемся добавить в словарь,
        // если ключ (буква) уже существует, то инкрементируем значение.
        is_new = freq_char.insert(pair<u_short, uint64_t>(ch, 1));
        if (!is_new.second)
            ++freq_char[ch];
        ch = (u_short) fin.get();
    }
    fin.close();

    for (auto i = freq_char.begin(); i != freq_char.end(); ++i)
        frequency.push_back(new Node(i->first, i->second));

    return frequency;
}

void bin_reader(string name) {

    fstream fin(name, ios::in | ios::out | ios::binary | ios::ate);

    if (!fin.is_open()) {
        cout << "File " << name << " doesn't exist!" << endl;
        return;
    }
    unsigned char byte = 0;
    for (int i = 0; i < 8; ++i) {
        byte = byte << 1;

        if (i % 2) {
            cout << "1";
            byte |= 1;
        }
        else {
            cout << "0";
        }

    }

    fin.write((char*) &byte, sizeof(byte));

    fin.close();
}

int main() {

//    vector<Node*> frequency = parser("simple.txt");
//    MinHeap heap(frequency);
//    CodeTree tree(&heap);
//    CodeDictionary codeDictionary(tree);
//    codeDictionary.printDictionary();
//
//    tree.printTree();
    short sh = 5;

    string byte;
    BinaryWriter bw("binary.txt");

    bw.writeBit(1);
    bw.writeBit(1);
    bw.writeBit(0);
    bw.writeBit(1);

    bw.writeBit(1);
    bw.writeBit(0);
    bw.writeBit(1);
    bw.writeBit(1);

    bw.write((char*) &sh, sizeof(sh));

    return 0;
}