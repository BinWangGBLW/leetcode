#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
 	int jump(vector<int>& nums) {
 		int step = 0;
 		int distance = 0;
 		int next = 0;
 		for (int i = 0; i < (int) nums.size() - 1; ++i) {
 			next = max(next, nums[i] + i);
 			if (i == distance) {
 				step++;
 				distance = next;
			 }
		 }
		return step;
	 }
};

int main() {
	vector <int> nums = {2, 3, 1, 1, 4};
	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}
