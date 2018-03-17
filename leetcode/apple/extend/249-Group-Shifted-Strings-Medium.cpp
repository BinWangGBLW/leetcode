/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

*/
#include <iostream>
#include <vector> 
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector <vector <string>> groupStrings(vector<string>& strings) {
        vector <vector <string>> res;
        unordered_map <string, multiset <string>> m;
        for (auto a : strings) {
            string t = "";
            for (auto c : a) {
                t += to_string((c + 26 - a[0])% 26) + ".";
            }
            m[t].insert(a);
        }
        for (auto it : m) {
            res.push_back(vector <string> (it.second.begin(), it.second.end()));
        }
        return res;
    }
};

int main() {
	vector <string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
	Solution s;
	vector <vector <string>> res = s.groupStrings(strings);
	for (int i = 0; i < (int) res.size(); ++i) {
		for (int j = 0; j <(int) res[i].size(); ++j)
			cout << res[i][j] <<"\t";
		cout << endl;
	}
	return 0;
}


