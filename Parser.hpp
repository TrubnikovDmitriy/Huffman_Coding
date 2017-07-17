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

    vector<Node*> parseOriginal(string original);
    bool reopen(string filename);
    u_short getSymbol();
    void close();
    bool eof();
private:
    ifstream fin;
};

#endif //PARSER_HPP
