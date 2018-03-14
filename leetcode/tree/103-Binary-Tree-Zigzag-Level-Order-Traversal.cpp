#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
iven a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]


*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> res;
        if (!root) return res;
        stack <TreeNode *> s1, s2;
        s1.push(root);
        vector <int> out;
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                TreeNode * cur = s1.top(); s1.pop();
                out.push_back(cur->val);
                if (cur->left) s2.push(cur->left);
                if (cur->right) s2.push(cur->right);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
            while(!s2.empty()) {
                TreeNode * cur = s2.top(); s2.pop();
                out.push_back(cur->val);
                if (cur->right) s1.push(cur->right);
                if (cur->left) s1.push(cur->left);
            }
            if (!out.empty()) res.push_back(out);
            out.clear();
        }
        return res;
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
  vector <string> a = {"3", "9", "20", "null", "null", "15", "7"};
  Createtree c;
  TreeNode *root = c.createTree(a);
  Solution s;
  vector <vector <int>> res = s.zigzagLevelOrder(root);
  c.printvec(res);
  return 0;
}

