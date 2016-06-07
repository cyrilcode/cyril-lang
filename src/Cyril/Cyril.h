//
//  Cyril.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_Cyril_h
#define cyril2_Cyril_h

#include "cmds.h"
//#include "CyrilState.h"

//class Particle;

void yyerror(const char *);

class Cyril {
public:
  bool valid;
  Cyril() { valid = true; }
  virtual ~Cyril () {}
  Cyril (const Cyril &other);
  virtual Cyril *clone ();
  virtual void print() { };
  virtual int size();
//  virtual void update(CyrilState &);
//  virtual void eval(CyrilState &);
  virtual int matchPushPop() { return 0; }
};

#endif

