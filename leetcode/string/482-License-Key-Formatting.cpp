#include <iostream>
#include <string>

using namespace std;

/*
You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4

Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
Example 2:
Input: S = "2-5g-3-J", K = 2

Output: "2-5G-3J"

Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.
*/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cnt = 0, n = (int) S.size();
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == '-') continue;
            if (S[i] >= 'a' && S[i] <= 'z') S[i] -= 32;
            res.push_back(S[i]);
            if (++cnt % K == 0) res.push_back('-');
        }
        if (!res.empty() && res.back() == '-') res.pop_back();
        return string(res.rbegin(), res.rend());
    }
};

int main() {
	string s = "5F3Z-2e-9-w";
	int k = 4;
	Solution ss;
	cout << "The new license is :" << ss.licenseKeyFormatting(s, k) << endl;
	return 0;
}
