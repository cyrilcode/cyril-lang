//
//  CyrilMoveOp.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef __cyril2__CyrilMoveOp__
#define __cyril2__CyrilMoveOp__


#include "Cyril/CyrilOp.h"

class CyrilMoveOp : public CyrilOp {
public:
  CyrilMoveOp(Cyril* _c);
  CyrilMoveOp (const CyrilMoveOp &other);
  virtual ~CyrilMoveOp ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
//  virtual void eval(CyrilState &);

    virtual void compile(instr_stack &stack)
    {
        c->compile(stack);
        switch (c->size())
        {
            case 2:
                stack.push_back({opcode::push, 0});
                break;
            case 1:
                stack.push_back({opcode::push, 0});
                stack.push_back({opcode::push, 0});
                break;
            default:
                // TODO: check this works!
                stack.push_back({opcode::load, 0, REG_TIME, "begin default rotate"});
                stack.push_back({opcode::push, 1000});
                stack.push_back({opcode::op_div});
                stack.push_back({opcode::fun, 0, FUN_SIN, "sin", 1});
                break;
        }
        stack.push_back({opcode::move});
    }

};



#endif /* defined(__cyril2__CyrilMoveOp__) */

//void CyrilMoveOp::eval(CyrilState &_s) {
//  c->eval(_s);
//  int s = c->size();
//  float x,y,z;
//  switch (c->size()) {
//    case 3:
//      z = _s.stk->top(); _s.stk->pop();
//      y = _s.stk->top(); _s.stk->pop();
//      x = _s.stk->top(); _s.stk->pop();
//      break;
//    case 2:
//      z = 0;
//      y = _s.stk->top(); _s.stk->pop();
//      x = _s.stk->top(); _s.stk->pop();
//      break;
//    case 1:
//      z = 0;
//      y = 0;
//      x = _s.stk->top(); _s.stk->pop();
//      break;
//    default:
//      z = 0;
//      y = 0;
//      x = sin((*_s.sym)[REG_TIME] / 1000);
//  }
//  ofTranslate(x, y, z);
//  _s.ms->translate(x, y, z);
//}