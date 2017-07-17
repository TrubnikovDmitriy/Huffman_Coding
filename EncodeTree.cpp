#include "CodeTree.hpp"
#include "Utils.hpp"



CodeTree::CodeTree(MinHeap *minHeap) {

    // Построение дерева кодирования
    Node* temp1 = minHeap->getMin();
    Node* temp2 = minHeap->getMin();
    Node* new_node;

    // Дерево не пустое
    assert(temp1 != nullptr);

    while(temp2 != nullptr) {
        new_node = makeBranch(temp1, temp2);
        minHeap->add(new_node);
        temp1 = minHeap->getMin();
        temp2 = minHeap->getMin();
    }
    root = temp1;
}
CodeTree::~CodeTree() {
    deleteNode(root);
}

Node* CodeTree::makeBranch(Node *left, Node *right) {

    Node* parent = new Node(UNION_SYMBOLS, left->amount + right->amount);
    parent->left = left;
    parent->right = right;
    return parent;
}
void CodeTree::deleteNode(Node *node) {

    if (node->left != nullptr)
        deleteNode(node->left);
    if (node->right != nullptr)
        deleteNode(node->right);
    delete node;
}

void CodeTree::printTree() {

    int depth = 0;

    if (root->right != nullptr)
        printTree(root->right, depth);

    std::cout << std::endl << root->amount;

    if (root->left != nullptr)
        printTree(root->left, depth);
}
void CodeTree::printTree(Node* node, int depth) {
    ++depth;

    if (node->right != nullptr)
        printTree(node->right, depth);

    for (int i = 0; i < depth; ++i) {
        std::cout << "\t";
    }
    std::cout << node->amount << "(" << (char)node->ch << ")" << std::endl;

    if (node->left != nullptr)
        printTree(node->left, depth);
}

Node* CodeTree::getRoot() {
    return root;
}