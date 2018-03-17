#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

class Solution {
 public:
 	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord};
        queue<vector<string>> paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string> words;
        while (!paths.empty()) {
            auto t = paths.front(); paths.pop();
            if (t.size() > level) {
                for (string w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if (level > minLevel) break;
            }
            string last = t.back();
            for (int i = 0; i < last.size(); ++i) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else paths.push(nextPath);
                }
            }
        }
        return res;
    }
};

int main(){
	vector <string> wordList = {"hot","dot","dog","lot","log","cog"};
	string beginWord = "hit", endWord = "cog";
	Solution s;
	vector <vector <string>> res = s.findLadders(beginWord, endWord, wordList);
	for (int i = 0; i < (int)res.size(); ++i) {
		for (int j = 0; j < (int) res[i].size(); ++j) {
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
