#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    helper(nums, res, 0);
    return res;
  }

  void helper(vector<int>& nums, vector<vector<int>>& res, int begin) {
    if (begin == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = begin; i < nums.size(); i++) {
      swap(nums[begin], nums[i]);
      helper(nums, res, begin + 1);
      swap(nums[begin], nums[i]);
    }
  }
};

int main() {
  vector<int> inputs = {1,2,3};
  vector<vector<int>> outputs;
  Solution sol; 
  outputs = sol.permute(inputs);

  cout << "Permution results are:\n";
  for (int i = 0; i < outputs.size(); i++) {
    for (int j = 0; j < outputs[0].size(); j++)
    	cout << outputs[i][j] << " ";
    cout << '\n';
  }

  return 0;
}
