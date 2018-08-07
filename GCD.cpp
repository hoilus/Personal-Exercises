#include <iostream>

using namespace std;

int GCD(int a, int b) {
  if (b == 0) return a;
  return a % b == 0 ? b : GCD(b, a % b);
}

int main() {

  cout << "GCD of 100 and 10 is " << GCD(100, 10) << '\n';
  cout << "GCD of 175 and 19 is " << GCD(175, 19) << '\n';
  cout << "GCD of 5 and 1 is " << GCD(5, 1) << '\n';
  cout << "GCD of 21 and 3 is " << GCD(21, 3) << '\n';

  return 0;
}
