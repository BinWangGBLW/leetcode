#include <iostream>
#include <vector>

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> val;
        val.resize(numRows);
        
        for (int i = 0; i < numRows; ++i) {
            val[i].resize(i+1);
            int m = val[i].size() - 1;
            val[i][0] = 1;
            val[i][m] = 1;
            for (int j = 1; j < m; ++j) {
                val[i][j] = val[i-1][j-1] + val[i-1][j];
            }
        }
        return val;        
    }
  // print the Pascal's triangle
  void print_pascal(vector<vector<int>> & val) {
    int rows = (int) val.size();
    for(int i = 0; i < rows; ++i)
    {
        for(int space = 0; space < rows-i; ++space)
        {
            cout <<" ";
        }
        for (int j = 0; j < (int) val[i].size(); ++j)
          cout << val[i][j] << " ";       
        cout << endl;
    }
  }
};

int main () {  
  Solution s;
  vector <vector <int>> val = s.generate(4);
  s.print_pascal(val);
}



