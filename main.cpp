#include <fstream>
#include <iostream>
#include <ctime>
#include <map>

#include "MinHeap.hpp"
#include "CodeTree.hpp"

using namespace std;


vector<Node*> parser(string name) {

    vector<Node*> frequency;

    ifstream fin(name);
    if (!fin.is_open()) {
        cout << "File " << name << " doesn't exist!" << endl;
        return frequency;
    }

    map<u_short, uint64_t> freq_char;
    u_short ch = (u_short)fin.get();
    pair<map<u_short, uint64_t>::iterator, bool> is_new;

    while(!fin.eof()) {

        // Считываем по одному символу и пытаемся добавить в словарь,
        // если ключ (буква) уже существует, то инкрементируем значение.

        is_new = freq_char.insert( pair<u_short, uint64_t>(ch, 1) );
        if (!is_new.second)
            ++freq_char[ch];
        ch = (u_short)fin.get();
    }
    fin.close();

    for (auto i = freq_char.begin(); i != freq_char.end(); ++i)
        frequency.push_back(new Node(i->first, i->second));

    return frequency;
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    srand((u_int)time(0));
//
//    const int N = 5;
//    vector<Node*> nodes;
//
//    for (int i = 0; i < N; ++i) {
//        int t = rand() % 100;
//        cout <<  t << endl;
//        nodes.push_back(new Node((uint64_t)t));
//    }
//    MinHeap heap(nodes);
//    cout << endl;
//
//    CodeTree tree(&heap);
//    tree.printTree();

    vector<Node*> frequency = parser("test.txt");
    return 0;
}
