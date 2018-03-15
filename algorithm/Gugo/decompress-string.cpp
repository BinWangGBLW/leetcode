#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

/*
> 给定一组char，包含({.小括号 Eg. : a(b(c){2}){2}d will be decompressed as abccbccd. {}中间的是前面（）里的内容的重复次数。
思路: 用栈，所有的往栈里压，直到），开始把上一个（之后的全部弹出到栈外，然后乘以倍数，然后翻转，再重新压到栈里，然后直到最后，全都弹出栈，翻转，就是结果了

*/

class Solution {
 public:
  string repeat_str(string &s) {
    stack <char> res;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] != ')') {
        if (s[i] != '{' && s[i] != '}')
          res.push(s[i]);
      }
      else {
        string tmp;
        while (true) {
          char t = res.top();
          res.pop();
          if (t == '(') 
            break;
          tmp += t;
        }
        reverse(tmp.begin(), tmp.end());
        i += 2;
        string num;
        while(s[i] >= '0' && s[i] <='9') {
          num += s[i++];
        }
        i--;
        int n = stoi(num);
        for (int j = 0; j < n; ++j) {
          for(auto a : tmp)
            res.push(a);
        }
      }
    }
    string ans;
    while(!res.empty()) {
        ans += res.top();
        res.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }   
};

int main()
{
    string s = "a(b(c){2}){2}d(efg){3}";
    Solution ss;
    cout << ss.repeat_str(s) << endl; 
   
   return 0;
}
