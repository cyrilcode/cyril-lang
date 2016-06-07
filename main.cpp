#include <iostream>
#include <Cyril/CyrilParser.h>

using namespace std;

int main() {
    const char *text =
                    "rotate\n"
                    "tile 3,3,3\n"
                    "   box 0.5\n"
                    "end\n";

    CyrilParser parser;
    Cyril* prog = parser.parseString(text);
    prog->print();
    return 0;
}
