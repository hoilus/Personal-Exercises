#ifndef _COPY_PROH_CONSTRUCTOR_STRING_APP_H_
#define _COPY_PROH_CONSTRUCTOR_STRING_APP_H_

class String {
public:
  String(char *str = ""); // constructor
  ~String(); // destructor

  void Display();

//  String(const String &other); // copy constructor
//  String & operator = (const String &other); // assignment overloading

private:
  char *str_;

  // private copy constructor and assignment overloading
  // to prevent copy and assignment operations
  // example in singleton pattern.
  // in this case, only delcare in private and no implementation.
  String(const String &other); // copy constructor
  String & operator = (const String &other); // assignment overloading
};

#endif 
