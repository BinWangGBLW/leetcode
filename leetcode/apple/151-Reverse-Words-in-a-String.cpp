#include <iostream>
#include <sstream>

/*
Reverse words in a string 151
 Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space? 

*/

using namespace std;

// 151 Reverse Words in a String
class Solution {
public:
  void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
  }
};

int main () {  
  string s = "the sky is blue";
  Solution s1;
  s1.reverseWords(s);
  cout << s << endl;
  return 0;
}



