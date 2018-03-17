#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map <char, int> m;
        for (auto c: s) {
            ++m[c];
        }
        int cnt = 0;
        for (auto it: m) {
            if (it.second %2) cnt++;
        }
        return cnt == 0 || (s.size()% 2 && cnt == 1);
    }
};

int main () {
	string s = "abcba";
	Solution ss;
	if (ss.canPermutePalindrome(s)) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}
