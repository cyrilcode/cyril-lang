
#ifndef CYRIL_LANG_EXAMPLE_INSTR_H
#define CYRIL_LANG_EXAMPLE_INSTR_H

#include <stack>
#include <vector>
#include <string>

enum class opcode
{
    box,
    rotate,
    push,
    tile,
    load,
    save,
    op_div,
    op_3toHex,
    dup,
    jump,
    jump_ifnot0,
    op_dec,
    move,
    fun,
};

class instruction
{
public:
    instruction(opcode o, float v_ = 0, int r_ = 0, std::string s = "", int f = 0)
            : op{o}, v{v_}, r{r_}, rem{s}, fs{f} {}
    opcode op;
    float v;
    int r;
    int fs; // size of fun
    std::string rem; // comments
};

std::string instructionAsString(instruction i);
std::string getOpCodeName(opcode o);


typedef std::vector<instruction> instr_stack;


#endif //CYRIL_LANG_EXAMPLE_INSTR_H
