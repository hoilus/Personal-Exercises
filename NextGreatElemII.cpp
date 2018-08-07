#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> nextGreatElements(vector<int>& nums) {
    vector<int> res(nums.size(), -1);
    stack<int> stk; // index stack
    
    for (int i = 0; i < 2 * nums.size(); i++) {
      int num = i % nums.size();
      while (!stk.empty() && nums[stk.top()] < nums[num]) {
        res[stk.top()] = nums[num];
        stk.pop();
      }
      if (i < nums.size()) stk.push(i);
    }

    return res;
  }
};

int main() {
  vector<int> nums = {1,2,1,2,3,0,10,2,45,3};
  Solution sol;
  vector<int> results = sol.nextGreatElements(nums);

  // print out results
  cout << "original nums are: ";
  for (auto z : nums) cout << z << " ";
  cout << '\n';
  cout << "NGE results are: ";
  for (auto z : results) cout << z << " ";
  cout << '\n';
 
  return 0;
}

