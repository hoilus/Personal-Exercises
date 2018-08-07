#include <iostream>

using namespace std;

class Shape {
public:
  int width, height;
public:
  virtual int getArea() {};
};

class Rect : public Shape {
public:
  int getArea(int w, int h) {
    width = w;
    height = h;
    return width * height;
  }
};

class Square : public Shape {
public:
  int getArea(int s) {
    width = s;
    height = s;
    return width * height;
  }
};

int main() {
  Rect rec;
  Square squ;
  cout << "The area is a rectangle is " << rec.getArea(10, 20) << '\n';
  cout << "The square area is " << squ.getArea(10) << '\n';

  return 0;
}
