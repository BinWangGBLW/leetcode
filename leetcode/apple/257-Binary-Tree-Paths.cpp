#include <iostream>
#include <vector>

/*
 Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        if (root) dfs(root, "", res);
        return res;
        
    }
    
    void dfs (TreeNode* root, string out, vector <string> &res) {
        out += to_string(root->val);
        if (!root->left && !root->right) res.push_back(out);
        else {
            if (root->left) dfs(root->left, out +"->", res);
            if (root->right) dfs(root->right, out+"->", res);
        }
    }
};

int main () {  
  Solution s;
  TreeNode a(1);
  TreeNode b(2);
  TreeNode c(3);
  TreeNode d(5);
  a.left = &b;
  a.right = &c;
  b.right = &d;
  vector <string> res = s.binaryTreePaths(&a);
  for (auto str: res) cout << str << endl;
  return 0;
}



