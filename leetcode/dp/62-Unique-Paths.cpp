#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 1 && n == 1) return 1;
        if (f_[m][n] > 0) return f_[m][n];
        int leftpath = uniquePaths(m - 1, n);
        int rightpath = uniquePaths(m, n - 1);
        f_[m][n] = leftpath + rightpath;
        return f_[m][n];
    }
private:
    unordered_map <int, unordered_map <int, int>> f_;
};

int main()
{
    int m = 6, n = 7;
    Solution ss;
    cout << "It has " << ss.uniquePaths(m, n) << " solutions" << endl; 
   
   return 0;
}
