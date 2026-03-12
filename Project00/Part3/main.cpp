#include <iostream>
#include <vector>

#include "part3.h"

int main() {
    const int width{400}, height{200};
    BackgroundColor background(400, 200, RGBColor(0,0,51), RGBColor(255,0,51), RGBColor(255,255,51), RGBColor(0,255,51));
    const int maxValue{255};

    std::cout << "P3\n";
    std::cout << width << " " << height << "\n";
    std::cout << maxValue << "\n";

    for(int row=0;row<height;row++) {
      for(int col=0;col<width;col++) {
        RGBColor color = background.sampleUV(col, row);
        std::cout << color.red << " " << color.green << " " << color.blue << "\n";
      }
    }

    return 0;
}