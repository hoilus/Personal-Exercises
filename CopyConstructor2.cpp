// an example class where copy constructor is needed!!

#include <iostream>
#include <cstring> // for strcpy

using namespace std;

class String {
private:
  char* s;
  int size;
public:
  String(const char *str = NULL); // constructor
  ~String() {delete [] s;} // destructor
  String(const String&); // copy constructor
  void print() {cout << s << endl;} // Function to print string
  void change(const char*); // Function to change
};

String::String(const char* str) {
  size = strlen(str);
  s = new char[size + 1];
  strcpy(s, str);
}

void String::change(const char* str) {
  delete [] s;
  size = strlen(str);
  s = new char[size + 1];
  strcpy(s, str);
}

// deep copy
String::String(const String& old_str) {
  size = old_str.size;
  s = new char[size + 1];
  strcpy(s, old_str.s);
}

int main() {
  String str1("String one");
  String str2 = str1; // deep copy if we have defined our own copy constructor
		      // otherwise, shallow copy if we only have default copy
   		      // constructor.

  str1.print();
  str2.print();
  str2.change("String two");
  str1.print();
  str2.print();

  return 0;
}
