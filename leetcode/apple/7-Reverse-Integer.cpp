#include <iostream>
#include <limits.h>

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21


*/

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main () {  
  int n = 123;
  Solution s;
  cout << s.reverse(n) << endl;
  return 0;
}



