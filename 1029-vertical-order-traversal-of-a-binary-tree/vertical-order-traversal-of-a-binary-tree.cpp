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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // just map the node with its row and column
        // vertical ---- > {level,multiset} 
        map<int,map<int,multiset<int>>> myMap;
        // write all componenet of the bfs
        // {node,{level,vertical}}

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();

                TreeNode* node = front.first;
                int level = front.second.first;
                int vertical = front.second.second;

                // mapping vertical index with
                myMap[vertical][level].insert(node -> val);

                if(node -> left != NULL)
                    q.push({node->left,{level+1,vertical-1}});
                if(node -> right != NULL)
                    q.push({node->right,{level+1,vertical+1}});
            }
        }

        vector<vector<int>>verticalOrder;
        for(auto p:myMap)
        {
            vector<int>res;
            for(auto q : p.second)
            {
                res.insert(res.end(),q.second.begin(),q.second.end());
            }
            verticalOrder.push_back(res);
        }
        return verticalOrder;
    }
};