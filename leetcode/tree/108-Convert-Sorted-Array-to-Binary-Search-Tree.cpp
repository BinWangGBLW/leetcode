#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size());
        
    }
    TreeNode* buildBST(vector <int> & nums, int l, int r) {
        if (l >= r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode * t = new TreeNode(nums[mid]);
        t->left = buildBST(nums, l, mid);
        t->right = buildBST(nums, mid + 1, r);
        return t;
    }
};

class Printtree {
  public:
 //levelorder traversal
    void levelOrder(TreeNode *root) {   
            
        queue<TreeNode *> q;  
        q.push(root);  
        q.push(0);  
          
        vector<string> level;  
        TreeNode *parent = nullptr;
        while(!q.empty())  
        {  
            TreeNode * cur = q.front();  
            q.pop();
            if(cur)  
            {  
                level.push_back(to_string(cur->val));    
                q.push(cur -> left);    
                q.push(cur -> right);  
            }
            else if (!cur && parent) {
              level.push_back("null");
            }
            parent = cur;
        }
        for (int i = 0; i < (int)level.size(); ++i)
          cout << level[i] << "\t";          
    }  
};


int main() {
  vector <int> tree = {-10,-3,0,5,9};
  Solution s;
  TreeNode *root = s.sortedArrayToBST(tree);
  Printtree p;
  p.levelOrder(root);
  return 0;
}

