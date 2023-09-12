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
    int maxPath(TreeNode* root,int& sum)
    {   
        if(root == NULL) return 0;

        int leftSum = max(0,maxPath(root -> left,sum));

        int rightSum = max(0,maxPath(root -> right,sum));

        int val = root -> val;

        sum = max(sum,((leftSum+rightSum)+val));

        return max(leftSum,rightSum)+val;

    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxPath(root,sum);
        return sum;
    }
};