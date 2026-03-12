#include <iostream>
#include <vector>

const std::vector<int> a={0,0,51}, b={255,0,51}, c={255,255,51}, d={0,255,51};
// const std::vector<int> a={0,255,51}, b={255,255,51}, c={255,0,51}, d={0,0,51};
const int width{400}, height{200};
const int maxValue{255};

std::vector<int> linearInterpolationX(const std::vector<int>& p1, const std::vector<int>& p2, int x) {
  std::vector<int> ans;
  float t = float(x)/width;
  for(int i=0;i<p1.size();i++) {
    int p = (1-t)*p1[i]+t*p2[i];
    ans.push_back(p);
  }
  return ans;
}

std::vector<int> linearInterpolationY(const std::vector<int>& p1, const std::vector<int>& p2, int y) {
  std::vector<int> ans;
  float t = float(y)/height;
  for(int i=0;i<p1.size();i++) {
    int p = (1-t)*p1[i]+t*p2[i];
    ans.push_back(p);
  }
  return ans;
}

std::vector<int> bilinearInterpolation(int x, int y) {
  std::vector<int> interpolationAB = linearInterpolationX(a, b, x);
  std::vector<int> interpolationDC = linearInterpolationX(d, c, x);
  std::vector<int> bInterpolation = linearInterpolationY(interpolationDC, interpolationAB, y);
  return bInterpolation;
}

void printColor(const std::vector<int> &color) {
  for(int colorComponent: color) {
    std::cout << colorComponent << " ";
  }
  std::cout << "\n";
}

int main() {
  std::cout << "P3\n";
  std::cout << width << " " << height << "\n";
  std::cout << maxValue << "\n";

  for(int row=0;row<height;row++) {
    for(int col=0;col<width;col++) {
      std::vector<int> color = bilinearInterpolation(col, row);
      printColor(color);
    }
  }

  return 0;
}