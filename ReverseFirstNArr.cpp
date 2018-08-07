#include <iostream>
#include <vector>

using namespace std;

void reverseNArr(vector<int>& nums, int n) {
  if (n > nums.size()) return;
  for (int i = 0, j = n - 1; i <= j; i++, j--)
    swap(nums[i], nums[j]);
}

int main() {
  vector<int> inputs = {1,3,4,2,9,10,2,3,4,1,10};
  reverseNArr(inputs, 5);
  for (auto z : inputs)
    cout << z << " ";
  cout << '\n';

  return 0;
}
