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

// class Solution {
// public:
//     int depth(TreeNode* root)
//     {
//         if(root == NULL) return 0;
//         return 1 + max(depth(root->left),depth(root -> right));
//     }
//     int diameter(TreeNode* root,int &diameter)
//     {
//     }
//     int diameterOfBinaryTree(TreeNode* root){
//         int diameter = 0;
//         diameter(root,diameter);
//         return diameter;
//     }
// };

class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int sumFromLeftRight = height(root -> left) + height(root -> right);

        int left = diameterOfBinaryTree(root -> left);
        int right = diameterOfBinaryTree(root -> right);

        return max(sumFromLeftRight,max(left,right));
    }
};