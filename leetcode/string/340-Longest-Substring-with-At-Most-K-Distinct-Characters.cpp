#include <iostream>
#include <string>

using namespace std;

/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int map[256] = { 0 };
		int res = 0, num = 0, j = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			if (map[s[i]]++ == 0) num++;
			if (num > k) {
				while (--map[s[j++]] > 0);
				num--;
			}
			res = max(res, i - j + 1);
		}
		return res;
	}
};

int main() {
	string s = "eceba";
	int k = 2;
	Solution ss;
	cout << "The length of the longest substring is :" << ss.lengthOfLongestSubstringKDistinct(s, k) << endl;
	return 0;
}
