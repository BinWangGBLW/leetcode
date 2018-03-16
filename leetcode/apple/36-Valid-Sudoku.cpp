#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

/*
这道题让我们验证一个方阵是否为数独矩阵，判断标准是看各行各列是否有重复数字，以及每个小的3x3的小方阵里面是否有重复数字，如果都无重复，
则当前矩阵是数独矩阵，但不代表待数独矩阵有解，只是单纯的判断当前未填完的矩阵是否是数独矩阵。
那么根据数独矩阵的定义，我们在遍历每个数字的时候，
就看看包含当前位置的行和列以及3x3小方阵中是否已经出现该数字，那么我们需要三个标志矩阵，
分别记录各行，各列，各小方阵是否出现某个数字，其中行和列标志下标很好对应，就是小方阵的下标需要稍稍转换一下。

*/

using namespace std;


class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector <vector <bool>> row(m, vector <bool> (n, false));
        vector <vector <bool>> col(m, vector <bool> (n, false));
        vector <vector <bool>> cell3(m, vector <bool> (n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (row[i][c] || col[c][j] || cell3[3*(i/3) + j/3][c])
                        return false;
                    row[i][c] = true;
                    col[c][j] = true;
                    cell3[3*(i/3) + j/3][c] = true;
                }
            }
        }
        return true;
    }

    void print_matrix(vector<vector<char>>& matrix) {
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
  vector<vector<char>> board(9, vector <char> (9, ' '));
  board[0][0] = '5';
  board[0][1] = '3';
  board[0][4] = '7';
  board[1][0] = '6';
  board[1][3] = '1';
  board[1][4] = '9';
  board[1][5] = '5';
  board[2][1] = '9';
  board[2][2] = '8';
  board[2][7] = '6';
  Solution ss;
  if (ss.isValidSudoku(board)) cout << "is valid sudoku" << endl;
  else cout << "is not a valid sudoku" << endl;
  return 0;
}



