//
//  CyrilRotateOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilRotateOp__
#define __cyril2__CyrilRotateOp__


#include "Cyril/CyrilOp.h"

class CyrilRotateOp : public CyrilOp {
public:
  CyrilRotateOp(Cyril* _c);
  CyrilRotateOp (const CyrilRotateOp &other);
  virtual ~CyrilRotateOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
//  virtual void eval(CyrilState &);

    virtual void compile(instr_stack &stack)
    {
        switch (c->size())
        {
            // TODO: other cases, if params supplied
            case 0:
            default:
                // TODO: finish this!
                // w = time / 36
                // x = 0, y = 1, z = 0.5
                stack.push_back({opcode::load, 0, REG_TIME, "begin default rotate"});
                stack.push_back({opcode::push, 36});
                stack.push_back({opcode::op_div});
                stack.push_back({opcode::push, 0});
                stack.push_back({opcode::push, 1});
                stack.push_back({opcode::push, 0.5});
                stack.push_back({opcode::rotate});
                // w = time / 64
                // x = 0, y = 0, z = 1
                stack.push_back({opcode::load, 0, REG_TIME});
                stack.push_back({opcode::push, 64});
                stack.push_back({opcode::op_div});
                stack.push_back({opcode::push, 0});
                stack.push_back({opcode::push, 0});
                stack.push_back({opcode::push, 1});
                stack.push_back({opcode::rotate, 0, 0, "end default rotate"});
        }
    }
};

#endif /* defined(__cyril2__CyrilRotateOp__) */
