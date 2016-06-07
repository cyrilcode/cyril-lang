//
//  CyrilNamedColor.h
//  Cyril
//
//  Created by Darren Mothersele on 18/11/2013.
//
//

#ifndef Cyril_CyrilNamedColor_h
#define Cyril_CyrilNamedColor_h


#include "cmds.h"
#include <map>

//extern std::map < std::string, ofColor > colorNameMap;


class CyrilNamedColor : public Cyril {
  std::string s;
  float r,g,b;
public:
  
  CyrilNamedColor(const char * _s) : s(_s) {
    
//    ofColor c = colorNameMap[s];
    // TODO: Need to replace colour name map with non-openFrameworks version!
    r = 0;//c.r;
    g = 0;//c.g;
    b = 0;//c.b;
    //cout << "Debug color: " << r << "," << g << "," << b << endl;
    valid = true;
  }
  CyrilNamedColor (const CyrilNamedColor &other) {
    s = other.s;
  }
  virtual ~CyrilNamedColor ()
  {
  }
  void print() {
      std::cout << "Named color: " << s << std::endl;
  }
  virtual Cyril *clone () { return new CyrilNamedColor (*this); }
  virtual int size() { return 3; }
//  virtual void eval(CyrilState &_s) {
//    _s.stk->push(r);
//    _s.stk->push(g);
//    _s.stk->push(b);
//  }
};


#endif
