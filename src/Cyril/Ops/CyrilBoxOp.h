//
//  CyrilBoxOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilBoxOp__
#define __cyril2__CyrilBoxOp__

#include "Cyril/CyrilOp.h"

class CyrilBoxOp : public CyrilOp {
public:
  CyrilBoxOp(Cyril* _c);
  CyrilBoxOp (const CyrilBoxOp &other);
  virtual ~CyrilBoxOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
//  virtual void eval(CyrilState &);
    virtual void compile(instr_stack &stack)
    {
        switch (c->size())
        {
            case 3:
                c->compile(stack);
                break;
            case 1:
                c->compile(stack);
                stack.push_back({opcode::dup});
                stack.push_back({opcode::dup});
                break;
            default:
                stack.push_back({opcode::push, 1});
                stack.push_back({opcode::push, 1});
                stack.push_back({opcode::push, 1});

        }
        stack.push_back({opcode::box});
    }
};


#endif /* defined(__cyril2__CyrilBoxOp__) */
