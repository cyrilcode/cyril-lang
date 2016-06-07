//
//  CyrilFftFun.h
//  Cyril
//
//  Created by Darren Mothersele on 15/11/2013.
//
//

#ifndef __Cyril__CyrilFftFun__
#define __Cyril__CyrilFftFun__

#include "CyrilFun.h"


extern float fftSubbands[32];

class CyrilFftFun : public CyrilFun {
public:
  CyrilFftFun(Cyril* _c);
  CyrilFftFun(const CyrilFftFun &other);
  virtual ~CyrilFftFun ();
  virtual void print();
  virtual Cyril *clone ();
  virtual int size();
};


#endif /* defined(__Cyril__CyrilFftFun__) */
