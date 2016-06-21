//
//  CyrilLoad.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilLoad_h
#define cyril2_CyrilLoad_h

#include "cmds.h"


class CyrilLoad : public Cyril {
  int loc;
public:
  CyrilLoad(int _i) : loc(_i) {
    valid = true;
  }
  CyrilLoad (const CyrilLoad &other) {
    loc = other.loc;
  }
  virtual ~CyrilLoad ()
  {
  }
  void print() {
      std::cout << "Load: " << loc << std::endl;
  }
  virtual Cyril *clone () { return new CyrilLoad (*this); }
  virtual int size() { return 1; }
//  virtual void eval(CyrilState &_s) {
//    //cout << "Load " << loc << ": " << (*_s.sym)[loc] << endl;
//    //cout << _s.sym->count(loc) << endl;
//      if ((*_s.sym)[loc] == 0 && (*_s.parent->sym)[loc] != 0) {
//          _s.stk->push((*_s.parent->sym)[loc]);
//      }
//      else {
//          _s.stk->push((*_s.sym)[loc]);
//      }
//  }


    virtual void compile(instr_stack &stack)
    {
        stack.push_back({opcode::load, 0, loc});
    }
};


#endif
