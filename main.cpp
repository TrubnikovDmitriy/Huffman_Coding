#include "Encode.hpp"
#include "Decode.hpp"


int main() {

    Encode *encode = new Encode("1.txt");
    encode->encode("bin");
    delete encode;

    Decode *decode = new Decode("bin");
    decode->decode("2.txt");
    delete decode;

    return 0;
}
