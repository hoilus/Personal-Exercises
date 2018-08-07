#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm> // for sort

using namespace std;

int main() {

  vector<string> inputs = {"Mike","Mike","Alice","Ram","Ram","Ali","Alice","Mike","Ram","Alice"};
  unordered_map<string, int> map_counts;

  for (auto z : inputs) ++map_counts[z];

  int max_counts = 1;
  vector<string> res;
  for (auto z : map_counts) {
    if (z.second > max_counts) {
      max_counts = z.second;
      res.clear();
      res.push_back(z.first);
    }
    else if (z.second == max_counts) {
      res.push_back(z.first);	
    }
  }

  // using lambda function to sort
  sort(res.begin(), res.end(), [](string a, string b) {return a[0] > b[0];});
  cout << "The winner is " << res[0] << '\n';

  return 0;
}
