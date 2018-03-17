#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) swap(nums[i], nums[j++]);
        }
    } 
};

int main() {
	vector <int> nums = {1, 0, 2, 3, 0, 0, 4, 5, 0, 7, 0, 9};
	Solution s;
	s.moveZeroes(nums);
	for (auto num : nums)
		cout << num << '\t';
	cout << endl;
	return 0;
}
