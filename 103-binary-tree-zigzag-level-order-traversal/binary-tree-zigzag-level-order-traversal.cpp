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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>zigZag;
        if(root == NULL) return zigZag;
        queue<TreeNode*>q;
        q.push(root);

        bool flag = 0;

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;

            for(int i=0;i<size;i++)
            {
                auto*temp = q.front();
                q.pop();

                if(temp -> left != NULL)
                {
                    q.push(temp -> left);
                }
                if(temp -> right != NULL)
                {
                    q.push(temp -> right);
                }

                level.push_back(temp -> val);
            }

            if(flag == 0)
            {
                zigZag.push_back(level);
                flag = 1;
            }
            else
            {
                reverse(level.begin(),level.end());
                zigZag.push_back(level);
                flag = 0;
            }
        }
        return zigZag;
    }
};