#include <iostream>

/*
 Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (needle.empty()) return 0;
        for (int i = 0; i <= m-n; ++i) {
            int j;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (n == j) return i;
        }
        return -1;
    }
};

int main () {  
  Solution s;
  cout << s.strStr("hello", "ll") << endl;
  return 0;
}



