#ifndef CODETREE_HPP
#define CODETREE_HPP

#include "MinHeap.hpp"
#include "BinaryReader.hpp"

class CodeTree {
public:
    CodeTree();
    ~CodeTree();

    uint32_t makeTree(BinaryReader *br);
    void makeTree(MinHeap *minHeap);
    void printTree();
    Node* getRoot();

private:
    Node* makeBranch(Node* left, Node* right);
    void deleteNode(Node* node);
    void printTree(Node* node, int depth);

    Node* root;
};

#endif //CODETREE_HPP
