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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int result=0;
        rec(root, result, L, R);
        return result;
    }
    void rec(TreeNode* root, int& result, int L, int R){
        if(root==NULL)
            return;
        if(root->val >= L && root->val <= R){
            result += root->val;
            rec(root->left, result, L, R);
            rec(root->right, result, L, R);
        }else if (root->val < L) {
            rec(root->right, result, L, R);
        }else if (root->val > R) {
            rec(root->left, result, L, R);
        }
        
    }
};