/*
  103. Binary Tree Zigzag Level Order Traversal - Medium

  Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and
  alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> queue;
        vector<TreeNode*> nextQueue;
        TreeNode* cur;
        bool forwards = true;
        
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
                    forwards = !forwards;
                }
                
                continue;
            }
            
            if (forwards) {
                result.back().push_back(cur->val);
            } else {
                result.back().insert(result.back().begin(), cur->val);
            }
            
            nextQueue.insert(nextQueue.begin(), cur->left);
            nextQueue.insert(nextQueue.begin(), cur->right);
            
            if (queue.empty() && !nextQueue.empty()) {
                queue = nextQueue;
                nextQueue.clear();
                result.push_back({ });
                forwards = !forwards;
            }
        }
        
        if (result.back().empty()) {
            result.pop_back();
        }
        
        return result;
    }
};