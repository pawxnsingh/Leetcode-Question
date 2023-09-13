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
    bool sym(TreeNode* tree1,TreeNode* tree2)
    {
        if(tree1 == NULL && tree2 == NULL) return true;

        if(tree1 == NULL || tree2 == NULL) return false;

        if(tree1 -> val == tree2 -> val)
            return sym(tree1 -> left,tree2 -> right) && sym(tree1 -> right,tree2 -> left);
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return sym(root->left,root->right);
    } 
};