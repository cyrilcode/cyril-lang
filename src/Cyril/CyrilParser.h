//
//  CyrilParser.h
//  cyril2
//
//  Created by Darren Mothersele on 05/11/2013.
//
//

#ifndef cyril2_CyrilParser_h
#define cyril2_CyrilParser_h


#include "Cyril.h"
#include "Lang/CyrilList.h"
//#include "Lang/CyrilOp.h"
#include "Lang/CyrilAssign.h"
#include "Lang/CyrilPush.h"
#include "Lang/CyrilDo.h"
#include "Lang/CyrilFor.h"
#include "Lang/CyrilIf.h"
#include "Lang/CyrilWhile.h"
#include "Lang/CyrilHexColor.h"
//#include "Lang/CyrilFun.h"
//#include "Lang/CyrilBinaryOp.h"
#include "Lang/CyrilLoad.h"
#include "Lang/CyrilUnaryOp.h"
//#include "Lang/CyrilParticle.h"

extern "C" int yyparse();
extern FILE *yyin;
extern "C" int line_no;
extern Cyril * pRoot;
extern int yycyrilParseString(const char *str);

class CyrilParser {
public:
  static Cyril* parseString(std::string progStr);
  static Cyril* parseFile(std::string fileName);
};

#endif

