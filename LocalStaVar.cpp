#include <iostream>

using namespace std;

int count_calls() {
  static int calls = 0;
//  int calls = 0;
  return ++calls;
}

int main () {

  for (int i = 0; i < 10; i++)
    cout << count_calls() << '\n';

  return 0;
}
