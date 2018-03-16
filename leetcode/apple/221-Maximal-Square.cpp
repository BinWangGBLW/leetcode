#include <iostream>
#include <vector>

/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 

*/

using namespace std;

class Solution {
public:

    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int i = 0; i < (int)matrix.size(); ++i) {
            vector<int> v(matrix[i].size(), 0);
            for (int j = i; j < (int)matrix.size(); ++j) {
                for (int k = 0; k <(int) matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = max(res, getsquarearea(v, j - i + 1));
            }
        }
        return res;
    }
    
    int getsquarearea(vector <int> &v, int k) {
        if ((int)v.size() < k) return 0;
        int count = 0;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i] != k) count = 0;
            else count++;
            if (count == k) return k*k;
        }
        return 0;
    }
  
    void print_matrix(vector<vector<char>>& matrix) {
      for (int i = 0; i < (int) matrix.size(); ++i) {
        for (int j = 0; j < (int) matrix[0].size(); ++j) {
          cout << matrix[i][j] << '\t';
        }
        cout << '\n';
      }
    }
};

int main () {  
  Solution s;
  vector <vector <char>> matrix = { {'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}
                                 };
  s.print_matrix(matrix);
  cout << s.maximalSquare(matrix) << endl;
  return 0;
}



