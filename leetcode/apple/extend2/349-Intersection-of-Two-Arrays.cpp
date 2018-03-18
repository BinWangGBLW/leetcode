#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> s(nums1.begin(), nums1.end()), res;
        for (auto num : nums2) {
            if (s.count(num)) res.insert(num);
        }
        return vector <int> (res.begin(), res.end());
    }
};

int main() {
	vector <int> nums1 = {1, 2, 2, 1};
	vector <int> nums2 = {2, 2};
	Solution s;
	vector <int> res = s.intersection(nums1, nums2);
	for (auto n : res)
		cout << n << '\t';
	cout << endl;
	return 0;
}
