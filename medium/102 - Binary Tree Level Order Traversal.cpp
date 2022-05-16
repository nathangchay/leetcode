/*
  102. Binary Tree Level Order Traversal - Medium

  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> queue;
        vector<TreeNode*> nextQueue;
        TreeNode* cur;
        
        result.push_back({ });
        queue.push_back(root);
        
        while (!queue.empty()) {
            cur = queue.back();
            queue.pop_back();
            
            if (cur == nullptr) {
                if (queue.empty() && !nextQueue.empty()) {
                    queue = nextQueue;
                    nextQueue.clear();
                    result.push_back({ });
                }
                
                continue;
            }
            
            result.back().push_back(cur->val);
            
            nextQueue.insert(nextQueue.begin(), cur->left);
            nextQueue.insert(nextQueue.begin(), cur->right);
            
            if (queue.empty() && !nextQueue.empty()) {
                queue = nextQueue;
                nextQueue.clear();
                result.push_back({ });
            }
        }
        
        if (result.back().empty()) {
            result.pop_back();
        }
        
        return result;
    }
};