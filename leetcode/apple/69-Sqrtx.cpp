#include <iostream>

/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

Example 1:

Input: 4
Output: 2

*/

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int i = 0, j = x / 2 + 1;
        while (i <= j) {
            long long mid = (i + j) / 2;
            long long sqr = mid * mid;
            if (sqr == x) return mid;
            else if (sqr < x) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }
};

int main () {  
  Solution s;
  cout << s.mySqrt(4) << endl;
  return 0;
}



