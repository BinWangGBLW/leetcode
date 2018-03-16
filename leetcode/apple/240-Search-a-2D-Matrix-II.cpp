#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.
*/

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int x = matrix.size() - 1, y = 0;
        while (x >=0 && y < (int)matrix[0].size()) {
            if (target > matrix[x][y]) ++y;
            else if (target < matrix[x][y]) --x;
            else return true;
        }
        return false;
    }
  
    void print_matrix(vector<vector<int>>& matrix) {
      int n = (int)matrix.size();
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << matrix[i][j] << '\t';
        }
        cout << '\n';
      }
    }
};

int main () {
  
  vector<vector<int>> matrix = {
                                  {1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                  {3,   6,  9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30},
                              };
  Solution ss;
  ss.print_matrix(matrix);
  if (ss.searchMatrix(matrix, 5)) cout << "true" << endl;
  else cout << "false" << endl;
  if (ss.searchMatrix(matrix, 20)) cout << "true" << endl;
  else cout << "false" << endl;
  return 0;
}



