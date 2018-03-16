#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> forward(n, 1), backward(n, 1), res(n);
        for (int i = 0; i < n - 1; ++i) {
            int j = n - 1 - i;
            forward[i + 1] = forward[i] * nums[i];
            backward[j - 1] = backward[j] * nums[j];
        }
        for (int i = 0; i < n; ++i) {
            res[i] = forward[i] * backward[i];
        }
        return res;
    }
};

int main() {
  vector <int> nums = {1, 3, -5, 7, 2, 3, 4, 4};
  Solution s;
  vector <int> res = s.productExceptSelf(nums);
  for (int i = 0; i < (int) res.size(); ++i) 
    cout << res[i] << '\t';
  cout << endl;
  return 0;
}

