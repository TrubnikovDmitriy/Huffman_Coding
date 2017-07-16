#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <cassert>
#include <vector>
#include <iostream>
#include "Utils.hpp"


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
