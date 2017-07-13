#include <iostream>
#include <ctime>

#include "MinHeap.hpp"
#include "CodeTree.hpp"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    srand((u_int)time(0));

    const int N = 5;
    vector<Node*> nodes;

    for (int i = 0; i < N; ++i) {
        int t = rand() % 100;
        cout <<  t << endl;
        nodes.push_back(new Node((uint64_t)t));
    }
    MinHeap heap(nodes);
    cout << endl;

    CodeTree tree(&heap);
    tree.printTree();


    return 0;
}
