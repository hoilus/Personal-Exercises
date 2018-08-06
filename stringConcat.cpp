#include <iostream>
#include <string>

using namespace std;

int main() {

  string str1 = "A129xa", str2 = "Buxy81";
  cout << str1 + str2 << '\n';
  cout << str1.insert(str1.size(), str2) << '\n';
  cout << str1.append(str2) << '\n';

  const char* cp = "stately, plump back";
  string str3;
  cout << str3.assign(cp, 7) << '\n';
  cout << str3.insert(str3.size(), cp + 7) << '\n';

  char cp1[] = "stately, plump back";
  string str4;
  cout << str4.assign(cp1, 7) << '\n';
  cout << str4.insert(str4.size(), cp1 + 7) << '\n';

  return 0;
}
