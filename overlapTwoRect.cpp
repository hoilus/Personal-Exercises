#include <iostream>
#include <utility> // std::pair, std::make_pair
#include <vector>

using namespace std;

int overlapAreaTwoRect(vector<pair<int, int>>& shape1, vector<pair<int, int>>& shape2) {
  vector<pair<int, int>> res; 

  // left bottom point of overlaped rectangule
  pair<int, int> pointLB;
  pointLB.first = max(shape1[0].first, shape2[0].first);
  pointLB.second = max(shape1[0].second, shape2[0].second);

  // right top point of overlaped rectangule
  pair<int, int> pointRT;
  pointRT.first = min(shape1[1].first, shape2[1].first);
  pointRT.second = min(shape1[1].second, shape2[1].second);

  // check whether overlaped rectangule should exist
  if (pointLB.first >= pointRT.first || pointLB.second >= pointRT.second)
    return 0;
  else {
    res.push_back(pointLB);
    res.push_back(pointRT);
    return (res[1].second - res[0].second) * (res[1].first - res[0].first);
  }

}

int main() {
  vector<pair<int, int>> shape1 = {{0, 0}, {1, 1}};
  vector<pair<int, int>> shape2 = {{2, 2}, {3, 8}};


  cout << "overlaped area is " << overlapAreaTwoRect(shape1, shape2) << '\n';

  return 0; 
}
