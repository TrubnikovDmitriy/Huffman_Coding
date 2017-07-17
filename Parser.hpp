#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <vector>
#include "Utils.hpp"

using namespace std;

class Parser {
public:
    Parser();
    Parser(string filename);
    ~Parser();

    bool reopen(string filename);
    void close();
    vector<Node*> parseOriginal(string original_file);
private:
    ifstream fin;
};

#endif //PARSER_HPP
