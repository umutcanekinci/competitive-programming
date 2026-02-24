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
    int sumRootToLeaf(TreeNode* root, int val=0) {
        
        val = val << 1;
        if (root->val) {
            val |= 1;
        }
        
        bool isLeaf = (root->left == nullptr && root->right == nullptr);
        if (isLeaf) {
            return val;
        }

        int sum = 0;
        if (root->left != nullptr) {
            sum += sumRootToLeaf(root->left, val);
        } 
        if (root->right != nullptr) {
            sum += sumRootToLeaf(root->right, val);
        } 
        return sum;
    } 
};