//
// Created by dmitriy on 12.07.17.
//

#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <cassert>
#include <vector>
#include <iostream>


struct Node {
    Node(uint64_t _a) {
        amount = _a;
        a = 0;
        left = nullptr;
        right = nullptr;
    }
    u_short a;
    uint64_t amount;
    Node* left;
    Node* right;
};
class MinHeap {
public:
    MinHeap() {};
    MinHeap(std::vector<Node*> &unheap);
    ~MinHeap() {};

    void add(Node* node);
    Node* getMin();

private:
    void siftUp(int i);
    void siftDown(int i);

    std::vector<Node*> array;
};

#endif //MIN_HEAP_HPP
