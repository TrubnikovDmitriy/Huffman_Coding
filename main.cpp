#include "Encode.hpp"
//
// TODO для оберток заменить указатели на ссылки!!
int main() {

    Encode *code = new Encode("simple.txt");
    code->encode("binary");

    delete code;
    BinaryReader* br = new BinaryReader("binary.dtv");
    CodeTree tree;
    tree.makeTree(br);
//    tree.printTree();
    CodeDictionary<string, u_short> dic;
    dic.makeDictionary(&tree);
    cout << endl;
    dic.printDictionary();

    return 0;
}
