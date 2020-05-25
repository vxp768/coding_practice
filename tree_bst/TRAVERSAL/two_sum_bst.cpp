/*
Given a Binary Search Tree and a target number, 
return true if there exist two elements in the BST such that their sum is equal to the given target.
*/

class BSTIterator {
    stack<TreeNode *> s;
    TreeNode *node;
    bool forward; //iterator supports both forward and backward movement
public:
    BSTIterator(TreeNode* root, bool fwd) {
        node = root; forward = fwd;
    };
    int next() {
        TreeNode *tmp;
        while(node || !s.empty()) {  //IN_ORDER traversal both increasing and decreasing
            if (node) {
                s.push(node);
                node = forward?node->left:node->right;
            } else {
                tmp = s.top();
                s.pop();
                int val = tmp->val;
                node = forward?tmp->right:tmp->left;
                return val;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator l(root,true);
        BSTIterator r(root,false);
        if (!root){
            return false;
        }
        for (int i = l.next(), j = r.next(); i<j; ) {
            int sum = i + j;  
            if (sum == k){
                return true;
            } else if (sum < k){
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;
    }
};