#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return distribute(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* distribute(vector <int> & preorder, int lp, int rp, vector <int> & inorder, int li, int ri) {
        if (lp > rp) return nullptr;
        TreeNode *root = new TreeNode(preorder[lp]);
        for (int k = li; k <= ri; ++k) {
            if (preorder[lp] == inorder[k]) {
                root->left = distribute(preorder, lp + 1, lp + (k - li), inorder, li, k - 1);
                root->right = distribute(preorder, lp + (k - li) + 1, rp, inorder, k + 1, ri);
            }
        }
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
  vector <int> preorder = {3,9,20,15,7};
  vector <int> inorder = {9,3,15,20,7};
  Solution s;
  Printtree p;
  TreeNode *root = s.buildTree(preorder, inorder);
  p.levelOrder(root);
  return 0;
}

