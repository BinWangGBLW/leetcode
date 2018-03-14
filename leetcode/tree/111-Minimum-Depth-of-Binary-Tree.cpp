#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 2.

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
        
    }
};

class Createtree {
  public:
 //levelorder traversal
  TreeNode* createTree(vector <string> a)
  {
    int n = (int) a.size();
    vector <TreeNode *> tree (n, nullptr);
    for(int i=0; i<n; i++) {
        if (a[i]== "null" ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(stoi(a[i]));
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        pushorder(root, 0, res);
        return res;
        
    }
  
    void pushorder(TreeNode*root, int level, vector <vector <int>> &res) {
        if (!root) return;
        if ((int)res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) pushorder(root->left, level + 1, res);
        if (root->right) pushorder(root->right, level + 1, res);
    }
  
    void printtree(TreeNode *root) {
      vector <vector <int>> res = levelOrder(root);
      cout << "[" << '\n';
      for(int i = 0; i < (int)res.size(); ++i) {
        cout << "[";
        int j = 0;
        for (j = 0; j < (int)res[i].size() - 1; ++j)
          cout << res[i][j] << ", ";
        cout << res[i][j] << "]\n";
      }
      cout << "]" << '\n';
    }
    void printvec(vector <vector <int>> &res) {
      cout << "[" << '\n';
      for(int i = 0; i < (int)res.size(); ++i) {
        cout << "[";
        int j = 0;
        for (j = 0; j < (int)res[i].size() - 1; ++j)
          cout << res[i][j] << ", ";
        cout << res[i][j] << "]\n";
      }
      cout << "]" << '\n';
    }
};


int main() {
  vector <string> tree = {"3","9","20","null","null","15","77"};
  Createtree c;
  TreeNode *root = c.createTree(tree);
  Solution s;
  cout << "The mindepth of tree is: " << s.minDepth(root) << endl;
  return 0;
}

