//
//  CurilDo.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CurilDo_h
#define cyril2_CurilDo_h

#include "cmds.h"

class CyrilDo : public Cyril {
  Cyril* e;
  Cyril* c;
public:
  CyrilDo(Cyril* _e, Cyril* _c) : e(_e), c(_c) {
    valid = c->valid;
    if (_e->size() != 1) {
      yyerror("Incorrect size of expression in do loop");
      valid = false;
    }
  }
  CyrilDo (const CyrilDo &other) {
    e = other.e->clone ();
    c = other.c->clone ();
  }
  virtual ~CyrilDo ()
  {
    delete e;
    delete c;
  }
  void print() {
    c->print();
    e->print();
    std::cout << "Do: " << std::endl;
  }
  virtual Cyril *clone () { return new CyrilDo (*this); }
  virtual int size() { return 0; }
//  virtual void eval(CyrilState &_s) {
//    e->eval(_s);
//    float val = _s.stk->top();
//    _s.stk->pop();
//    while (val > 0) {
//      c->eval(_s);
//      val--;
//    }
//  }
  virtual int matchPushPop() { return c->matchPushPop(); }


    virtual void compile(instr_stack &stack)
    {
      e->compile(stack);
      instr_stack temp;
      c->compile(temp);
      for (auto i : temp)
      {
        i.rem += " (in loop)";
        stack.push_back(i);
      }
      stack.push_back({opcode::op_dec, 1});
      stack.push_back({opcode::jump_ifnot0, 0, (int)temp.size() + 1});
    }
};


#endif
