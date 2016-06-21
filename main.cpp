#include <iostream>
#include <iomanip>
#include <Cyril/CyrilParser.h>

using namespace std;



int main() {
    const char *text =
                    "x: 0\n"
                    "do 4 times\n"
                    "  move x, 0\n"
                    "end\n"
                    "rotate\n"
                    "tile 3,3,3\n"
                    "   box 0.5\n"
                    "end\n";

    CyrilParser parser;
    Cyril* prog = parser.parseString(text);

    instr_stack p;
    prog->compile(p);

    cout << "Compiled program (size " << p.size() << "):" << endl;
    int pc = 0;
    for (auto i : p)
    {
        cout << setfill('0') << setw(5) << pc++ << "\t" << instructionAsString(i) << endl;
    }

    return 0;
}
