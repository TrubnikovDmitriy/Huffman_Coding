//
// Created by dmitriy on 12.07.17.
//


#include "MinHeap.hpp"


MinHeap::MinHeap(std::vector<Node*> &unheap) {
    array = unheap;
    int i = (int)(unheap.size() / 2 - 1);
    for (int j = i; j >= 0; --j) {
        siftDown(j);
    }
}

Node* MinHeap::getMin() {

    if (array.empty())
        return nullptr;

    Node* temp = array[0];
    std::swap(array[0], array[array.size() - 1]);
    array.pop_back();
    siftDown(0);
    return temp;
}
void MinHeap::add(Node* node) {

    array.push_back(node);
    siftUp((int)array.size() - 1);
}

void MinHeap::siftUp(int i) {

    assert(i < array.size());
    if (i < 1) return;
    int parent = (i - 1) / 2;
    if (array[parent]->amount > array[i]->amount) {
        std::swap(array[parent], array[i]);
        siftUp(parent);
    }
    return;
}
void MinHeap::siftDown(int i) {

    assert(i >= 0);

    if (i >= array.size() - 1)
        return;

    int min;
    if ((i + 1) * 2 < array.size()){

        if (array[(i + 1) * 2 - 1]->amount < array[(i + 1) * 2]->amount)
            min = (i + 1) * 2 - 1;
        else
            min = (i + 1) * 2;

        if (array[i]->amount > array[min]->amount) {
            std::swap(array[i], array[min]);
            siftDown(min);
        }
        return;
    } else {
//        std::cout << "gg";
        if ((i + 1) * 2 - 1 < array.size() && array[i]->amount > array[(i + 1) * 2 - 1]->amount) {
                std::swap(array[i], array[(i + 1) * 2 - 1]);
                siftDown((i + 1) * 2 - 1);
        }
    }
    return;
}

