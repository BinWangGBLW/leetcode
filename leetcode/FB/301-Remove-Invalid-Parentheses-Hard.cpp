#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

class Solution {
public:
    bool isValids(string &s) {
        int count = 0;
        for (auto c : s){
            if (c == '(') ++count;
            if (c == ')') --count;
            if (count < 0) return false;
        }
        return count == 0;
    }   
    void dfs(string &s, int start, int l, int r, vector <string> &ans) {
        if (l == 0 && r== 0) {
            if (isValids(s)) {
                ans.push_back(s);
                return;
            }
        }
        
        for (int i = start; i < s.size(); ++i) {
            if (i != start && s[i] == s[i-1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string cur = s;
                cur.erase(i, 1);
                if (r > 0 && s[i] == ')') dfs(cur, i, l, r - 1, ans);
                else if (l > 0 && s[i] == '(') dfs(cur, i, l - 1, r, ans);
            }
        }
    }
    vector<string> removeInvalidParentheses(string &s) {
        int l = 0, r = 0;
        for (auto c : s) {
            l += (c == '(');
            if (l == 0) r += (c == ')');
            else
                l -= (c == ')');
        }
        vector <string> ans;
        dfs(s, 0, l, r, ans);
        return ans;
    }
};

int main() {
	string s = "(a)())()";
	Solution ss;
	vector <string> ans = ss.removeInvalidParentheses(s);
	for (auto cc : ans)
		cout << cc << '\t';
	cout << endl;
}
