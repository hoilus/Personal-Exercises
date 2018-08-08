#include <iostream>

using namespace std;

// A copy constructor is a member function which initiates an object 
// using another object of the same class. 
// A copy constructor has the following general prototype
// ClassName (const ClassName& old_obj)

class Point {
private:
  int x, y;
public:
  Point(int x1, int y1) {
    x = x1; y = y1;
  }

  // copy constructor
  Point(const Point &p2) {
   x = p2.x; y = p2.y;
  }

  int getX() {return x;}
  int getY() {return y;}
};

int main() {
  Point p1(10, 15), p2(1, 3);
  Point p3 = p1; // call copy constructor
  p2 = p1; // class assignment

  cout << p1.getX() << " " << p1.getY() << '\n';
  cout << p2.getX() << " " << p2.getY() << '\n';
  cout << p3.getX() << " " << p3.getY() << '\n';

  return 0;
}
