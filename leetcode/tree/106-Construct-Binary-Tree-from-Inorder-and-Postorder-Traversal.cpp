#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    unordered_map <int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;
        for (int i = 0; i < (int)inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return distribute(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode *distribute(vector <int> & inorder, int li, int ri, vector <int> &postorder, int lp, int rp) {
        if (li > ri || lp > rp) return nullptr;
        TreeNode *root = new TreeNode(postorder[rp]);
        int k = m[postorder[rp]];
        int s = k - li;
        root->left = distribute(inorder, li, k - 1, postorder, lp, lp + s - 1);
        root->right = distribute(inorder, k + 1, ri, postorder, lp + s, rp - 1);
        return root;
    }
};

class Printtree {
  public:
 //levelorder traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        int max = maxDepth(root);
        level_print(root, nullptr, 0, max);
        return res;
        
    }
  
    void level_print(TreeNode*root, TreeNode *parent, int level, int m) {
        if (level == m || (!root && !parent)) return;
        if (!root && parent) {
          cout << "null ";
          return;
        }
        cout << root->val << "\t";
        level_print(root->left, root, level + 1, m);
        level_print(root->right, root, level + 1, m);
    }
  
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lmax = maxDepth(root->left);
        int rmax = maxDepth(root->right);
        return max(lmax, rmax) + 1;
    }
  
};


int main() {
  vector <int> inorder = {3,9,20,15,7};
  vector <int> postorder = {9,3,15,20,7};
  Solution s;
  Printtree p;
  TreeNode *root = s.buildTree(inorder, postorder);
  p.levelOrder(root);
  return 0;
}
