#ifndef UTILS_HPP
#define UTILS_HPP

#include <map>
#include <cassert>

#define MAX_SYMBOLS 100
#define UNION_SYMBOLS 0


typedef std::map<unsigned short, std::string> dic_map;

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

#endif //UTILS_HPP
