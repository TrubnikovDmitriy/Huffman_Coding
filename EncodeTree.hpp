#ifndef CODETREE_HPP
#define CODETREE_HPP

#include "MinHeap.hpp"

class CodeTree {
public:
    CodeTree(MinHeap* minHeap);
    ~CodeTree();
    Node* getRoot();

    void printTree();

private:
    Node* makeBranch(Node* left, Node* right);
    void deleteNode(Node* node);
    void printTree(Node* node, int depth);

    Node* root;
};

#endif //CODETREE_HPP
