#include <iostream>

int main() {
    const int width{400}, height{200};
    const int maxValue{255};

    std::cout << "P3\n";
    std::cout << width << " " << height << "\n";
    std::cout << maxValue << "\n";

    for(int row=0;row<height;row++) {
        float greenScale = float(row)/(height-1);
        for(int col=0;col<width;col++) {
            float redScale=float(col)/(width-1); 
            int red = redScale*maxValue;
            int green = (1-greenScale)*maxValue;
            int blue = maxValue*0.2;
            std::cout << red << " " << green << " " << blue << "\n"; 
        }
    }

    return 0;
}