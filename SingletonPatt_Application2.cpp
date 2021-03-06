/*
  When we want a class to generate the same object to the client service, 
  such as managing database connections, managing I/O files, et al., 
  we will use the singleton pattern.

  https://blog.csdn.net/eric491179912/article/details/6708379
*/

#include <iostream>

using namespace std;

class Singleton {
private:
  // private constructor
  Singleton();

  // private copy constructor, only declare not implement
  Singleton(const Singleton&);

  // Private assignment operator, only declare not implement
  Singleton & operator = (const Singleton&);

//  virtual ~Singleton(); // destructor

  // the single static instance 
  static Singleton instance;

  int var; // for test code

public:
  // to obtain the single private instance
  // here return by pointer not reference, 
  // otherwise it violates the single instance charaterist of singleton
  static Singleton &GetInstance();

  int getVar(); // get var
  
  void setVar(int); // set var
};

// Implement constructor
Singleton::Singleton() {
  this->var = 20;

  cout << "Singleton Constructor\n";
}
/*
Singleton::~Singleton() {
  delete instance;
}
*/
// Initiate static members
Singleton Singleton::instance = Singleton();
Singleton& Singleton::GetInstance() {
  return instance;
}

// getVar()
int Singleton::getVar() {
  return this->var;
}

// setVar(int)
void Singleton::setVar(int var) {
  this->var = var;
}

// main
int main(int argc, char* argv[]) {
  Singleton& ton1 = Singleton::GetInstance();
  Singleton& ton2 = Singleton::GetInstance();

  cout << "ton1 var = " << ton1.getVar() << '\n';

  ton1.setVar(100);

  // note that construtor is only called once
  // ton1 and ton2 point to the same object
  cout << "ton2 var = " << ton2.getVar() << '\n';

  /*
  result is:
  Single Constructor
  ton1 var = 20
  ton2 var = 100
  */

  Singleton& tonxx = ton1; // this will work, as initiated by pointer. 

  Singleton ton3 = ton1; // prohibit copy constructor
 
  ton2 = ton1; // prohibit assignment constructor

  return 0;
}
