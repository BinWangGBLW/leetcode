#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> res;
    	for (unsigned int i=0; i<nums.size(); i++) {
        	if ((i>0) && (nums[i]==nums[i-1]))
            	continue;
        	int l = i+1, r = nums.size()-1;
        	while (l<r) {
            	int s = nums[i]+nums[l]+nums[r];
            	if (s>0) r--;
            	else if (s<0) l++;
            	else {
                	res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                	while (nums[l]==nums[l+1]) l++;
                	while (nums[r]==nums[r-1]) r--;
                	l++; r--;
            	}
        	}
    	}
    	return res;
	}
};

int main() {
	vector <int> nums = {-1, 0, 1, 2, -1, -4};
	Solution s;
	vector <vector <int>> res = s.threeSum(nums);
	for (auto vec : res) {
		for (auto num : vec) 
			cout << num << '\t';
		cout << endl;
	}
	return 0;
}
