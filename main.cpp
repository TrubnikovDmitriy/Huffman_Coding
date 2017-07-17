#include "Encode.hpp"



using namespace std;


int main() {

    string filename("simple.txt");

    Encode* code = new Encode(filename);
    code->encode("binary.txt");

    delete code;
    return 0;
}