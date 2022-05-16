/*
  101. Symmetric Tree - Easy

  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        TreeNode* leftCur;
        TreeNode* rightCur;
        vector<TreeNode*> leftStack;
        vector<TreeNode*> rightStack;
        
        leftStack.push_back(root->left);
        rightStack.push_back(root->right);
        
        while (!leftStack.empty() && !rightStack.empty()) {
            leftCur = leftStack.back();
            rightCur = rightStack.back();
            leftStack.pop_back();
            rightStack.pop_back();
            
            if (leftCur == nullptr && rightCur == nullptr) {
                continue;
            }
            
            if (leftCur == nullptr && rightCur != nullptr || rightCur == nullptr && leftCur != nullptr || leftCur->val != rightCur->val) {
                return false;
            }
            
            // cout << "Compared " << leftCur->val << " and " << rightCur->val << endl;
            
            leftStack.push_back(leftCur->left);
            leftStack.push_back(leftCur->right);
            
            rightStack.push_back(rightCur->right);
            rightStack.push_back(rightCur->left);
        }
        
        return true;
    }
};