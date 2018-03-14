#include <iostream>
using namespace std;
/*
一个N*N的grid, 里面battleship是一个横着或者竖着的一条线（三个格子）， 要找到battleship的坐标 可以每次隔3个格子 按行扫、按列扫，输出坐标需要输出battleship的三个格子的各自坐标...

实在一个square里面找battership的位置，battership会连续占据三个的位置，或是横着或是竖着。 里面会有一个给定函数来判断给定位置是不是有船，最后要求输出battership占据三个位置的坐标。
Battleship game: write a function that finds a ship and return its coordinates.

思路: 首先判断前后左右，如果是有船，就添加。其次再扫描3 * 3 格，找到所有的坐标
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Battleboard {
public:
  set <pair <int, int>> checkaround(vector <vector <char>> &board, int x, int y) {
    set <pair <int, int>> res;
    int max = (int)board.size() - 1;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
      int m = dx[i] + x;
      int n = dy[i] + y;
      if (m >=0 && m <= max && n >= 0 && n <= max) {
        if (board[m][n] == 'X') {
          if (board[x][y] == 'X') res.insert({x, y});
          else res.insert({m, n});
        }
      }
    }
    return res;
  } 
  set <pair <int, int>> findplot(vector <vector <char>> &board, int n, int step) {
    set <pair <int, int>> res;
    for (int i = 0; i < n; ++i) {
      for (int j = i % 3; j < n; j += step) {
        set <pair <int, int>> tmp = checkaround(board, i, j);
        if (!tmp.empty()) {
          for (auto it : tmp) {
            if (!res.count(it)) res.insert(it);
          }
        }
      }      
    }
    return res;
  }
};

// To execute C++, please define "int main()"
int main() {
  int n = 8, step = 3;
  vector <vector <char>> board (n, vector <char> (n, '-'));
  board[1][1] = 'X';
  board[2][3] = 'X';
  board[3][3] = 'X';
  board[4][3] = 'X';
  board[5][4] = 'X';
  board[5][5] = 'X';
  board[5][6] = 'X';
  Battleboard ss;
  set <pair <int, int>> res = ss.findplot(board, n, step);
  cout << "All the coordinate battleships are:" << endl;
  for(auto it : res) 
    cout <<"(" << it.first << ", " << it.second << ")\n";
  return 0;
}
