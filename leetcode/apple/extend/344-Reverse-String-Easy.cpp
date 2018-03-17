#include <iostream>
#include <stack>
using namespace std;

class Solution {
 public:
 	string reverse_Str(string &s) {
 		stack <char> p;
 		for(auto c : s) {
 			p.push(c);
		 }
		string res = "";
		while(!p.empty()) {
			res += p.top();
			p.pop();
		}
		return res;
	 }
};

int main() {
	string s = "hello";
	Solution ss;
	cout << ss.reverse_Str(s) << endl;
	return 0;
}
