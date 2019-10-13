/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //return result in vector of vector, one vector for each level
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> result;
        if(root==NULL) return result;
        vector<int> lvl;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            for(int i=0; i<size; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                lvl.push_back(node->val);
                if(node->left)
                    Q.push(node->left);
                if(node->right)
                    Q.push(node->right);
            }
            result.push_back(lvl);
            lvl.clear();
        }
        return result;
    }
};

//Simple level order traversal
