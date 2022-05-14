/*
  783. Minimum Distance Between BST Nodes - Easy

  Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
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
private:
    vector<int> values;
public:
    int diff(int a, int b) {
        return std::abs(a - b);
    }
    
    void recurse(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        
        values.push_back(node->val);
        
        recurse(node->left);
        recurse(node->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        recurse(root);
        
        int min = diff(values[0], values[1]);
        
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < values.size(); j++) {
                if (i != j) {
                    if (diff(values[i], values[j]) < min) {
                        min = diff(values[i], values[j]);
                    }
                }
            }
        }
        
        return min;
    }
};