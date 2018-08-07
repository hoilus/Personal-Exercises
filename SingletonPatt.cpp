#include <iostream>

// a singleton class should have public visibility
// so that complete application can use
class GFG {

  //static instance of class globally accessible
public:
  static GFG instance = new GFG();

private:
  GFG() {
    //private constructor so that class cannot
    // be instantiated from outside this class
  }

};
