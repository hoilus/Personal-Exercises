/*
Sort an array according to the order defined by another array.
Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

This is a Amazon interview question. I will try two approaches.
1. Hashmap
2. Writing a customized compare function.

https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> // for sort

using namespace std;

vector<int> A2 = {2, 1, 8, 3, 4};

int search(int key, vector<int> A2) {
  int i = 0, idx = 0;
  for (i = 0; i < A2.size(); i++)
    if (A2[i] == key)
      return i;
  return -1;
}

bool compareByA2 (int a, int b) {
  int idx1 = search(a, A2);
  int idx2 = search(b, A2);
  if (idx1 != -1 && idx2 != -1)
    return (idx1 < idx2);
  else if (idx1 != -1)
    return true;
  else if (idx2 != -1)
    return false;
  else
    return (a < b);
}

class SORTARRAY {
private:
  vector<int> B1, B2;

public:
  SORTARRAY(vector<int> A1, vector<int> A2) {
    B1 = A1;
    B2 = A2;
  }

  void HashMethod() {
    // step 1, HashMap of A1, key is unique element, val is how many time it occurs
    unordered_map<int, int> HashMap;
    for (int i = 0; i < B1.size(); i++)  ++HashMap[B1[i]];
    B1.clear();

    // step 2, loop A2, if A2[i] exists in HashMap, output the element by val times;
    // erase the element
    for (auto z : B2) {
      if (HashMap.find(z) != HashMap.end()) {
	B1.insert(B1.end(), HashMap[z], z);
	HashMap.erase(z);
      }
    }
    int B1_size_tmp = B1.size();

    // step 3, insert the left key members in HashMap back to A1, and sort them.
    for (const auto &w : HashMap)
      B1.insert(B1.end(), w.second, w.first);
    sort(B1.begin() + B1_size_tmp, B1.end());
    HashMap.clear(); // clear HashMap
  }

  void printA1() {
    for (int i = 0; i < B1.size(); i++)
      cout << B1[i] << " ";
    cout << '\n';
  }

  void CustCompByA2Method() {
    sort(B1.begin(), B1.end(), compareByA2); // compareByA2 must be defined out of class as a global func()
  }

};

int main() {

//  vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
//  vector<int> A2 = {2, 1, 8, 3};
  vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8, 7, 5, 6, 9, 7, 5};
//  vector<int> A2 = {2, 1, 8, 3, 4};

  SORTARRAY solution(A1, A2);
//  solution.HashMethod();
//  solution.printA1();

  // This approach needs to defin A2 as a global vector;
  solution.CustCompByA2Method();
  solution.printA1();

  return 0;
}
