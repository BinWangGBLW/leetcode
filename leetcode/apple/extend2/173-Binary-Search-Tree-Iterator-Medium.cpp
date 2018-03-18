/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/ 
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            ss.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !ss.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = ss.top();
        ss.pop();
        int val = tmp->val;
        if (tmp->right) {
            tmp = tmp->right;
            while(tmp) {
                ss.push(tmp);
                tmp = tmp->left;
            }
        }
        return val;
    }
private:
    stack <TreeNode *> ss;
};

/*Build a BST using sorted list */

class BuildBST {
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

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
 int main() {
 	BuildBST b;
 	vector <int> sort_list = {-8, -5, -3, 0, 1, 2, 3, 5};
 	TreeNode *root = b.sortedArrayToBST(sort_list);
 	BSTIterator i = BSTIterator(root);
 	while (i.hasNext()) cout << i.next() << '\t';
 	cout << endl;
 	return 0;
 }
