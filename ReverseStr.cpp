#include <iostream>
#include <string>

using namespace std;

int main() {
  string st1 = "How are you";
  string st2, tmp = st1;
  size_t found;
  found = st1.find_last_of(" ");
  while (found != string::npos) {
    st2 += st1.substr(found + 1);
    st2 += " ";
    st1 = st1.substr(0, found);
    found = st1.find_last_of(" ");
  }
  st2 += st1;

  cout << "original string is " << tmp << '\n';
  cout << "Reverse string is " << st2 << '\n';

  return 0;
}
