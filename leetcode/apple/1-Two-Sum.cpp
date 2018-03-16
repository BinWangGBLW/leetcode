#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res(2);
        unordered_map <int, int> m;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!m.count(target - nums[i])) 
                m[nums[i]] = i;
            else {
                res[0] = m[target - nums[i]];
                res[1] = i;
                break;
            }
        }
        return res;
    }
};

int main () {
  vector <int> nums = {-1, 0, 2, 3, 4, 5};
  Solution s;
  vector <int> res(2); 
  int target = 1;
  res= s.twoSum(nums, target);
  for (auto n: res) cout << n << '\t';
  cout << endl;
  return 0;
}
