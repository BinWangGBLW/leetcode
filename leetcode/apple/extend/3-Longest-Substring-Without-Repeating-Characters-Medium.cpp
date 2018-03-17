#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> m;
        int res = 0;
        for (int i = 0, j = 0; i < (int) s.size(); ++i) {
            if (m.count(s[i])) {
                j = max(j, m[s[i]] + 1);
            }
            m[s[i]] = i;
            res = max(res, i - j + 1);
        }
        return res;
    }
};

int main() {
	string s= "abcbcamn";
	Solution ss;
	cout << ss.lengthOfLongestSubstring(s) << endl;
	return 0;
}
