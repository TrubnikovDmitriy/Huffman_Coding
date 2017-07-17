#include <iostream>
#include "Parser.hpp"

Parser::Parser() {};
Parser::Parser(string filename) {

    fin.open(filename, ios::in);
    if (!fin.is_open())
        cout << "File " << filename << " doesn't exist!" << endl;
}
Parser::~Parser() {
    fin.close();
}

bool Parser::reopen(string filename) {

    fin.close();
    fin.open(filename, ios::in);

    if (!fin.is_open()) {
        cout << "File " << filename << " doesn't exist!" << endl;
        return false;
    }
    return true;
}
void Parser::close() {
    fin.close();
}
vector<Node*> Parser::parseOriginal(string original_file) {

    fin.close();
    vector<Node*> frequency;

    fin.open(original_file, ios::in);
    if (!fin.is_open()) {
        cout << "File " << original_file << " doesn't exist!" << endl;
        return frequency;
    }

    map<u_short, uint64_t> freq_char;
    pair<map<u_short, uint64_t>::iterator, bool> is_new;

    u_short ch = (u_short) fin.get();

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