#ifndef GUERREIRO_H 
#define GUERREIRO_H

#include <vector>

struct RGBColor {
  int red;
  int green;
  int blue;

  RGBColor(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
  }
};

class BackgroundColor {
  private:
    int width, height;
    std::vector<RGBColor> corners;
    RGBColor linearInterpolation(const RGBColor &A, const RGBColor &B, float t ) const;

    enum Corners_e {
      bl=0, //!< Bottom left corner.
      br,    //!< Bottom right corner.
      tr,   //!< Top right corner.
      tl   //!< Top left corner.
    };
  public:
    BackgroundColor(const int width, const int height, const RGBColor bottomLeft, const RGBColor bottomRight, const RGBColor topRight, const RGBColor topLeft);
    
    ~BackgroundColor() {}
    
    RGBColor sampleUV(int u, int v) const;
};

#endif