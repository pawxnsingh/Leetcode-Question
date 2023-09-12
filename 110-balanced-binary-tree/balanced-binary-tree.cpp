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
    // this function is taking the O(logN)
    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = depth(root -> left);
        int right = depth(root -> right);
        return 1 + max(left,right);
    }
    // this also takes O(N)
    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;

        int leftHeight = depth(root-> left);
        int rightHeight = depth(root -> right);

        if(abs(leftHeight - rightHeight) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);

    }   
    // O(NlogN) overall;
    // SC :- O(N) worst case if the tree is skewed
};

