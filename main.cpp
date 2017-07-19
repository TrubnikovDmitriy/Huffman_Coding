#include "Encode.hpp"
#include "Decode.hpp"
//

int main() {

    Encode *encode = new Encode("Makefile");
    encode->encode("binary");
    delete encode;

    Decode *decode = new Decode("binary.dtv");
    decode->decode("resimple.txt");
    delete decode;

    return 0;
}
