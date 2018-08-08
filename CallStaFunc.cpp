#include <iostream>

using namespace std;

class Shape {
private:
  int width;
  int height;
public:
  Shape(int w, int h) {
    width = w;
    height = h;
    ++count;
  }
  int getArea() {
    return width * height;
  }

  static int count;
  static int callingTimes() {
    return count;
  }
};

//static member initializer
int Shape::count = 0;

int main() {
  Shape shape1(10, 15), shape2(1, 8), shape3(2, 4);
  // call non-static member
  cout << shape1.getArea() << '\n';

  cout << Shape::callingTimes() << '\n';

  return 0;
}
