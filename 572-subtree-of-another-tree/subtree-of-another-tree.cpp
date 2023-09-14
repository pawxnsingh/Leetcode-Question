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

// Intuition and thought Process
// break the problem into two step

// Step 1: traverse the root node and find the subRoot Equivalent
        // if found return the node named as subRoot_2
        // else return NULL

// Step 2: traverse the subRoot and SubRoot_2 and check if they are equal or not
        // if equal return true;
        // else return false;

class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p -> val == q -> val){
            return isSame(p->left,q->left) && isSame(p->right,q->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;

        if(isSame(root,subRoot)) return true;

        return isSubtree(root -> left,subRoot) || isSubtree(root -> right,subRoot);
    }
};