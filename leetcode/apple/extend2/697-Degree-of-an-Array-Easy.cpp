/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = (int)nums.size(), degree = 0;
        unordered_map <int, int> m;
        unordered_map <int, pair <int, int>> interval;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (++m[nums[i]] == 1) {
                interval[nums[i]] = {i, i};
            }
            else {
                interval[nums[i]].second = i;
            }
            degree = max(degree, m[nums[i]]);
        }
        
        for (auto a : m) {
            if (degree == a.second) 
                res = min(res, interval[a.first].second - interval[a.first].first + 1);
        }
        return res;
    }
};

int main() {
	Solution ss;
	vector <int> a = {1, 2, 2, 3, 1};
	cout << ss.findShortestSubArray(a) << endl;
	return 0;
}
