#include "instr.h"

std::string instructionAsString(instruction i)
{
    std::string t = getOpCodeName(i.op);

    if (i.op == opcode::push)
        t += "\t\t" + std::to_string(i.v);
    else if (i.op == opcode::load)
        t += "\t\t" + std::to_string(i.r) + "\t\t";
    else if (i.op == opcode::save)
        t += "\t\t" + std::to_string(i.r) + "\t\t";
    else if (i.op == opcode::jump)
        t += "\t\t" + std::to_string(i.r) + "\t\t";
    else if (i.op == opcode::jump_ifnot0)
        t += "\t\t" + std::to_string(i.r) + "\t\t";
    else if (i.op == opcode::fun)
        t += "\t\t" + std::to_string(i.r) + ":" + std::to_string(i.fs) + "\t\t";
    else
        t += "\t\t\t\t";

    if (i.rem != "")
    {
        t += "\t\t; " + i.rem;
    }
    return t;
}

std::string getOpCodeName(opcode o)
{
    switch(o)
    {
        case opcode::box:
            return "box";
        case opcode::rotate:
            return "rotate";
        case opcode::push:
            return "push";
        case opcode::tile:
            return "tile";
        case opcode::load:
            return "load";
        case opcode::save:
            return "save";
        case opcode::dup:
            return "dup";
        case opcode::jump:
            return "jump";
        case opcode::jump_ifnot0:
            return "jump_!0";
        case opcode::move:
            return "move";
        case opcode::fun:
            return "fun";

        case opcode::op_div:
            return "op_div";
        case opcode::op_3toHex:
            return "op_3toHex";
        case opcode::op_dec:
            return "op_dec";

        default:
            return "unknown";
    }
}
