#include "Encode.hpp"

int main() {

    Encode *code = new Encode("Encode.cpp");
    code->encode("binary");

    delete code;
    return 0;
}
