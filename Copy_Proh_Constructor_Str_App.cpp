#include "Copy_Proh_Constructor_Str_App.h"
#include <iostream>
#include <cstring>

using namespace std;

// constructor
String::String(char *str) {
  int size = strlen(str);
  str_ = new char[size + 1];
  strcpy(str_, str);
}
/*
// copy constructor for deep copy
String::String(const String &other) {
  int size = strlen(other.str_);
  str_ = new char[size + 1];
  strcpy(str_, other.str_);
}
*/
// destructor
String::~String() {
  delete [] str_;
}

void String::Display() {
  cout << str_ << '\n';
}
/*
// assignment overloading
String & String::operator = (const String &other) {
  if (this == &other)
    return *this;

  delete [] str_;

  int size = strlen(other.str_);
  str_ = new char[size + 1];
  strcpy(str_, other.str_);
  return *this;
}
*/
// main
int main(int argc, char* argv[]) {

  String s1("AAB");
  s1.Display();

  String s2 = s1;

  String s3;
  s3.Display();
  s3 = s2;

  /*
  error shown when we want to prevent copy constructor and assignment operator:
Copy_Proh_Constructor_Str_App.cpp(49): error #373: "String::String(const String &)" (declared at line 15) is inaccessible
    String s2 = s1;
                ^

Copy_Proh_Constructor_Str_App.cpp(53): error #373: "String &String::operator=(const String &)" (declared at line 22 of "Copy_Proh_Constructor_Str_App.h") is inaccessible
    s3 = s2;
  */

  return 0;
}
