//
//  Palette.h
//  cyril2
//
//  Created by Darren Mothersele on 06/11/2013.
//
//

#ifndef __cyril2__Palette__
#define __cyril2__Palette__

#include <vector>

class PaletteItem {
public:
//  ofColor c;
float c[3];
  float distance;
  
  PaletteItem(float _d, int _hex) {
//    c = ofColor::fromHex(_hex);
      // TODO: replace ofColor from Hex
    distance = _d;
  }
  PaletteItem(float _d, float _r, float _g, float _b) {
//    c = ofColor(_r, _g, _b);
      c[0] = _r; c[1] = _g; c[2] = _b;
    distance = _d;
  }
};

class Palette {
  float total;
  std::vector<PaletteItem> colors;
public:
  Palette();
  void addColor(float, int);
  void addColor(float, float, float, float);
//  ofColor getColor(float);
//  ofColor randomColor();
//  ofColor getColorAt(float);
//  ofColor lerp(float);
  Palette (const Palette &other) ;
  virtual ~Palette ();
  virtual Palette *clone ();
  void drawBackground();
};


#endif /* defined(__cyril2__Palette__) */
