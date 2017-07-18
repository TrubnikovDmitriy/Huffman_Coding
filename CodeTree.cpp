#include <stack>
#include "CodeTree.hpp"
#include "Utils.hpp"


CodeTree::CodeTree() {
    root = nullptr;
}
CodeTree::~CodeTree() {
    deleteNode(root);
}

void CodeTree::makeTree(MinHeap *minHeap) {

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
void CodeTree::makeTree(BinaryReader *br) {
    // Заранее оговорено, что структура закодированного файла будет следующей:
    //    - первые 2 байта - количетсво нод
    //    - следующие 2 байта - количество узлов
    //    - дерево кодирования, сложенное по определенном алгоритму
    //    - сразу за деревом, закодированный текст.

    u_short lists, nodes;
    br->read((char*)&lists, sizeof(u_short));
    br->read((char*)&nodes, sizeof(u_short));

    std::stack<Node*> stack;

    u_short count_lists = 0;
    u_short count_nodes = 0;
    Node *right, *left;
    u_short ch;
    int flag;

    while(count_nodes < nodes || count_lists < lists) {
        flag = br->readBit();
        if (flag == 1) {
            ++count_lists;

            ch = br->readByte();
            stack.push(new Node(ch, 0));
        }
        if (flag == 0) {
            ++count_nodes;

            right = stack.top();
            stack.pop();
            left = stack.top();
            stack.pop();
            Node* new_node = new Node();
            new_node->right = right;
            new_node->left = left;
            stack.push(new_node);
        }
    }
    assert(stack.size() == 1);
    root = stack.top();
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