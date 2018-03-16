#include <iostream>
#include <map>

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char, int> m;
        for (auto c : magazine)
          ++m[c];
        for (auto c: ransomNote) {
          if (--m[c] < 0) return false;
        }
        return true;
    }
};

int main() {
  Solution s;
  if (s.canConstruct("aa", "aab")) cout << "true" <<endl;
  else cout <<"false" <<endl;
  return 0;
}



