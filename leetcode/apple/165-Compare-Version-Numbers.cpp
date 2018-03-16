#include <iostream>

/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

*/

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string v1, v2;
        int i = 0, j = 0, d1 = 0, d2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                v1.push_back(version1[i++]);
            }
            d1 = atoi(v1.c_str());
            while (j < n2 && version2[j] != '.') {
                v2.push_back(version2[j++]);
            }
            d2 = atoi(v2.c_str());
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            ++i;
            ++j;
            v1.clear(); v2.clear();
        }
        return 0;
    }
};

int main () {  
  Solution s;
  cout << s.compareVersion("1.1", "0.1") << endl;
  return 0;
}



