#include <iostream>
#include <map>
#include <vector>

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int max_left = 0, max_right = 0, ans = 0;
    int left = 0, right = (int) height.size() - 1;
    while (left <right) {
      if (height[left] <= height[right]) {
        max_left = max(max_left, height[left]);
        ans += max_left - height[left];
        left++;
      }
      else {
        max_right = max(max_right, height[right]);
        ans += max_right - height[right];
        right--;
      }
    }
    return ans;
  }
};

int main () {
  vector <int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution s;
  cout << s.trap(height) << endl; 
  return 0;
}



