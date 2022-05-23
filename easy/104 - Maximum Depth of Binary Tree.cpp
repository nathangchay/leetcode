/*
  104. Maximum Depth of Binary Tree - Easy

  Given the root of a binary tree, return its maximum depth.

  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 1;
        vector<TreeNode*> stack;
        vector<int> stackDepth;
        TreeNode* cur;
        int curDepth;
        
        if (root == nullptr) {
            return 0;
        }
        
        stack.push_back(root);
        stackDepth.push_back(1);
        
        while (!stack.empty()) {
            cur = stack.back();
            stack.pop_back();
            
            curDepth = stackDepth.back();
            stackDepth.pop_back();
            
            if (cur == nullptr) {
                continue;
            }
            
            result = max(result, curDepth);
            
            stack.push_back(cur->left);
            stackDepth.push_back(curDepth + 1);
            
            stack.push_back(cur->right);
            stackDepth.push_back(curDepth + 1);
        }
        
        return result;
    }
};