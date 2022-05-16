/*
  98. Validate Binary Search Tree - Medium

  Given the root of a binary tree, determine if it is a valid binary search tree (BST).

  A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root) {
        TreeNode* cur;
        vector<TreeNode*> leftStack, rightStack;
        
        if (root->left != nullptr) {
            leftStack.push_back(root->left);
        }
        
        if (root->right != nullptr) {
            rightStack.push_back(root->right);
        }
        
        while (!leftStack.empty()) {
            cur = leftStack.back();
            leftStack.pop_back();
            
            if (cur->val >= root->val) {
                return false;
            }
            
            if (cur->left != nullptr) {
                leftStack.push_back(cur->left);
            }
            
            if (cur->right != nullptr) {
                leftStack.push_back(cur->right);
            }
        }
        
        while (!rightStack.empty()) {
            cur = rightStack.back();
            rightStack.pop_back();
            
            if (cur->val <= root->val) {
                return false;
            }
            
            if (cur->left != nullptr) {
                rightStack.push_back(cur->left);
            }
            
            if (cur->right != nullptr) {
                rightStack.push_back(cur->right);
            }
        }
        
        
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        } else if (root->left == nullptr) {
            return isValidBST(root->right);
        } else if (cur->right == nullptr) {
            return isValidBST(root->left);
        } else {
            return isValidBST(root->right) && isValidBST(root->left);
        }
    }
};