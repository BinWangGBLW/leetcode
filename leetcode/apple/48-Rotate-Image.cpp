#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = (int)matrix.size();
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          int tmp = matrix[i][j];
          matrix[i][j] = matrix[n - 1 - j][i];
          matrix[n - 1 -j][i] = matrix[n - 1 - i][n - 1 -j];
          matrix[n - 1 - i][n - 1 -j] = matrix[j][n -1 - i];
          matrix[j][n -1 - i] = tmp;
        }
      }  
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
                        {15,13, 2, 5},
                        {14, 3, 4, 1},
                        {12, 6, 8, 9},
                        {16, 7,10,11} 
                        };
  Solution s;
  s.print_matrix(matrix);
  s.rotate(matrix);
  cout << endl;
  s.print_matrix(matrix);
  return 0;
}
