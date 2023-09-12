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
    // this function is taking the O(N)
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

        bool leftPart = isBalanced(root->left);
        bool rightPart = isBalanced(root -> right);

        if(leftPart == false || rightPart == false) return false;

        return true;
    }   
    // O(N) overall;
};

