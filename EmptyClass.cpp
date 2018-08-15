/*
class Empty() {}; // this is an empty class

there have 6 default members in an empty class:
Empty(); // default constructor
Empty(const Empty &); // default copy constructor
~Empty(); // default destructor
Empty &operator = (const Empty &); // default assignment operator overloading
Empty *operator&(); // default getting address operator overloading
const Empty *operator &() const; // default getting address operator of const 
*/

#include <iostream>

using namespace std;

class Empty {
public:
  Empty * operator&() {
    cout << "AAA\n";
    return this;
  }

  const Empty * operator&() const {
    cout << "BBB\n";
    return this;
  }

};

int main() {
  Empty e;
  Empty *ep = &e;

  const Empty e2;
  const Empty *e2p = &e2;

  cout << sizeof(Empty) << '\n';

  return 0;
}
