#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

using namespace std;

int main() {
  vector<int> v = {1, 3, 2, 1, 3, 5, 7, 5, 1, 3, 6, 9, 6, 2};
  auto getUniqueNums = [](vector<int> &nums) {
      unordered_set<int> s;
      for (auto &i: nums) if (!s.count(i)) s.insert(i);
      vector<int> res;
      res.reserve(s.size());
      for (auto &i: s) res.push_back(i);
      auto up = make_unique<vector<int>>(res);
      return up;
  };
  auto unique_nums = getUniqueNums(v);
  for (auto &i: *unique_nums) cout << i << " ";
  return 0;
}
