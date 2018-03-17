/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector <string>> res;
        unordered_map <string, vector <string>> m;
        for (string str: strs) {
            string t = str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }
        for (auto it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};

int main() {
	Solution s;
	vector <string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector <vector <string> > ans = s.groupAnagrams(strs);
	for (auto str : ans) {
		for (auto it : str) {
			cout << it << '\t';
		}
		cout << endl;
	}
	return 0;
}
