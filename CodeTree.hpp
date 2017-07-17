#ifndef CODETREE_HPP
#define CODETREE_HPP

#include "MinHeap.hpp"
#include "BinaryReader.hpp"

class EncodeTree {
public:
    EncodeTree();
    ~EncodeTree();

    void makeEncodeTree(MinHeap* minHeap);
    void makeDecodeTree(BinaryReader* br);
    void printTree();
    Node* getRoot();

private:
    Node* makeBranch(Node* left, Node* right);
    void deleteNode(Node* node);
    void printTree(Node* node, int depth);

    Node* root;
};

#endif //CODETREE_HPP
