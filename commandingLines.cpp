#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Only one argument is allowed.\n";
    exit(1);
  }

  if (argv[1][0] == '-') {
    cout << "Usage options are not provided. All settings can be found in the parameter input file.\n";
    exit(1);
  }

  for (int i = 0; i < argc; i++) {
    cout << argv[i] << '\n';
  }

  return 0;
}
