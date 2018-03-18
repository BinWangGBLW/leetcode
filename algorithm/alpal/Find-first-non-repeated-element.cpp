/*
Find first non-repeated element in a string
*/
#include <iostream>
#include <string>

/*
flag = false

abcdacdea
i = 0 flag = false
j -> 1 - n
 index[4].val  == index[1].val
 flag = true 


*/

using namespace std;

class Solution {
public:
	char findfirstnonrepeat(string &s) {
		int n = (int)s.size();
		bool flag = false;
		for (int i = 0; i < n; i ++) {
			flag = false;
			for (int j = 0; j < n; j++) {
				if ( i != j && s[j] == s[i]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				return s[i];
			}
		}
		return ' ';
	}
};

int main() {
	string s = "abcdacdeb";
	Solution ss;
	cout << ss.findfirstnonrepeat(s) <<endl;
}
