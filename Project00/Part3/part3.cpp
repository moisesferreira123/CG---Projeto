#include <iostream>
#include <vector>
#include "part3.h"

BackgroundColor::BackgroundColor(const int width, const int height, const RGBColor bottomLeft, const RGBColor bottomRight, const RGBColor topRight, const RGBColor topLeft) {
  this->width = width;
  this->height = height;
  RGBColor bl(bottomLeft.red, bottomLeft.green, bottomLeft.blue);
  RGBColor br(bottomRight.red, bottomRight.green, bottomRight.blue);
  RGBColor tr(topRight.red, topRight.green, topRight.blue);
  RGBColor tl(topLeft.red, topLeft.green, topLeft.blue);
  corners.assign({bl, br, tr, tl});
}

RGBColor BackgroundColor::linearInterpolation(const RGBColor &a, const RGBColor &b, float t ) const {
  int red = (1-t)*a.red+t*b.red;
  int green = (1-t)*a.green+t*b.green;
  int blue = (1-t)*a.blue+t*b.blue;
  return RGBColor(red,green,blue);
}

RGBColor BackgroundColor::sampleUV(int u, int v) const {
  RGBColor interpolationBottom = linearInterpolation(corners[bl], corners[br], float(u)/width);
  RGBColor interpolationTop = linearInterpolation(corners[tl], corners[tr], float(u)/width);
  RGBColor bilateralInterpolation = linearInterpolation(interpolationTop, interpolationBottom, float(v)/height);
  return bilateralInterpolation;
}