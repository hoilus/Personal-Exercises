#include <iostream>

using namespace std;

class Base {
private:
  int x;
public:
  virtual void fun() = 0; // pure virtual function
  int getX() {
    return x;
  }
};

class Derived : public Base {
private:
  int y;
public:
  void fun() {cout << "fun() called from Derived.\n";}
};

int main() {
  Derived d;
  d.fun();
  return 0;
}

