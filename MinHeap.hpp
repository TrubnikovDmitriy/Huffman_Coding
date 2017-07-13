//
// Created by dmitriy on 12.07.17.
//

#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <cassert>
#include <vector>
#include <iostream>


struct Node {
    Node(u_short _ch, uint64_t _am) {
        ch = _ch;
        amount = _am;
        left = nullptr;
        right = nullptr;
    }
    u_short ch;
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
