#include <fstream>
#include <iostream>
#include <ctime>

#include "MinHeap.hpp"
#include "CodeTree.hpp"

using namespace std;


void parser(string name) {

    ifstream fin(name);
    if (!fin.is_open()) {
        cout << "File " << name << " doesn't exist!" << endl;
        return;
    }
    for (int i = 0; i < 10; ++i) {
        int ch = fin.get();
        cout << ch << " = " << (char)ch << endl;
    }
    fin.close();
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

    parser("test.txt");
    return 0;
}
